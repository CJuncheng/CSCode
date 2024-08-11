#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int* buffer;
	int capacity;
	int read_index;
	int write_index;
	int size;
} RingBuffer;

RingBuffer* create(int capacity) {
	RingBuffer* ring = (RingBuffer*)malloc(sizeof(RingBuffer));
	if (ring == NULL) {
		return NULL;
	}

	ring->buffer = (int*)malloc(capacity * sizeof(int));
	if (ring->buffer == NULL) {
		free(ring);
		return NULL;
	}

	ring->capacity = capacity;
	ring->read_index = 0;
	ring->write_index = 0;
	ring->size = 0;

	return ring;
}

void destroy(RingBuffer* ring) {
	if (ring == NULL) {
		return;
	}

	free(ring->buffer);
	free(ring);
}

void write(const int* data, int data_count, RingBuffer* ring) {
	for (int i = 0; i < data_count; i++) {
		if (ring->size == ring->capacity) {
			handle_full_buffer(ring); // 如果buffer满则创建一个更大的buffer
		}

		ring->buffer[ring->write_index] = data[i];
		ring->write_index = (ring->write_index + 1) % ring->capacity;
		ring->size++;
	}
}

int read(int* data, int size, RingBuffer* ring) {
	int num_elements_to_read = (size < ring->size) ? size : ring->size;

	for (int i = 0; i < num_elements_to_read; i++) {
		data[i] = ring->buffer[ring->read_index];
		ring->read_index = (ring->read_index + 1) % ring->capacity;
	}

	ring->size -= num_elements_to_read;
	return num_elements_to_read;
}

int free_size(RingBuffer* ring) {
	return ring->capacity - ring->size;
}

bool empty(RingBuffer* ring) {
	return ring->size == 0;
}

bool full(RingBuffer* ring) {
	return ring->size == ring->capacity;
}

int size(RingBuffer* ring) {
	return ring->size;
}


void handle_full_buffer(RingBuffer* ring) {
	int new_capacity = ring->capacity * 2; // 容量扩展2倍
	int* new_buffer = (int*)malloc(new_capacity * sizeof(int));
	if (new_buffer == NULL) {
		return;
	}

	// 拷贝旧数据
	int data_count = 0;
	int* data = (int*)malloc(ring->capacity * sizeof(int));
	while (!empty(ring)) {
		data[data_count] = ring->buffer[ring->read_index];
		ring->read_index = (ring->read_index + 1) % ring->capacity;
		data_count++;
	}

	// 释放旧 buffer 的内存
	free(ring->buffer);

	// 更新 ring buffer 的属性
	ring->buffer = new_buffer;
	ring->capacity = new_capacity;
	ring->read_index = 0;
	ring->write_index = data_count; // 新 buffer 的写指针设置为数据拷贝后的位置
	ring->size = data_count;

	// 将数据从临时数组拷贝回 ring buffer
	for (int i = 0; i < data_count; i++) {
		ring->buffer[i] = data[i];
	}

	// 释放临时数组的内存
	free(data);
}