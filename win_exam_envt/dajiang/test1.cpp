#include <iostream>
#include <vector>
#include <stack>

struct Node {
    std::string name;
    std::vector<Node*> children;
};

void buildFileSystem(Node* root, std::vector<std::string>& paths, int level) {
    while (!paths.empty()) {
        std::string path = paths.front();
        int pathLevel = 0;
        while (path[pathLevel] == '-') {
            pathLevel++;
        }
        if (pathLevel == level) {
            Node* node = new Node;
            node->name = path.substr(pathLevel);
            root->children.push_back(node);
            paths.erase(paths.begin());
            buildFileSystem(node, paths, level + 1);
        } else {
            break;
        }
    }
}

void searchFiles(Node* root, const std::string& keyword, std::string currentPath) {
    if (root == nullptr) {
        return;
    }
    currentPath += "/" + root->name;
    if (root->name.find(keyword) != std::string::npos) {
        std::cout << currentPath << std::endl;
    }
    for (Node* child : root->children) {
        searchFiles(child, keyword, currentPath);
    }
}

int main() {
    std::string keyword;
    std::getline(std::cin, keyword);
    int numLines;
    std::cin >> numLines;
    std::cin.ignore();

    std::vector<std::string> paths;
    for (int i = 0; i < numLines; i++) {
        std::string path;
        std::getline(std::cin, path);
        paths.push_back(path);
    }

    Node* root = new Node;
    buildFileSystem(root, paths, 0);

    searchFiles(root, keyword, "");

    return 0;
}