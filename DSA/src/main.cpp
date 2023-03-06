#include <iostream>
#include <string>
#include "list.h"
#include "share.h"
#include "stack.h"
#include "queue.h"
#include "bin_tree.h"
#include "graph.h"
#include "bin_search_tree.h"
#include "avl_tree.h"

namespace list {
   void testList(void)
   {
      List<int> list;
      list.insertAsFirst(1);
      cout << list.header->succ->data << endl;
   }
}

namespace stackandqueue {
void testStackAndQueue(void)
{
   // 4.3.1 逆序输出 -> 进制转换
   Stack<char> stackConvert;
   convert_(stackConvert, 12345, 8);
   while (!stackConvert.empty())
   {
      std::cout << stackConvert.top();
      stackConvert.pop();
   }
   std::cout << std::endl;

   // 4.3.2 递归嵌套 -> 括号匹配
   char parentheses_str1[] = "a / ( b [ i - 1 ] [ j + 1 ] + c [ i + 1 ] [ j - 1 ] ) * 2";
   char parentheses_str2[] = "a / ( b [ i - 1 ] [ j + 1 ] ) + c [ i + 1 ] [ j - 1 ] ) * 2";
   std::cout << parentheses_str1 << " is match: " << paren(parentheses_str1, 0, 56) << std::endl;
   std::cout << parentheses_str2 << " is match: " << paren(parentheses_str2, 0, 58) << std::endl;
   // 4.3.3 延迟缓冲 -> 中缀表达式 4.3.4 逆波兰表达式
   char exp[] = "(1+2)*3^4";
   std::string RPN = "";
   std::cout << exp << "=" << evaluate(exp, RPN) << std::endl; //(1+2)*3^4=243
   std::cout << "RPN is:" << RPN << std::endl;                 // RPN is:12+34^*

   // 队列的应用 -> 银行服务模型
   simulate(10, 60 * 8);
}
}
namespace bintree{
int testID = 0; //测试编号
template <typename T>
bool randomBinTree(BinTree<T> &bt, BinNodePosi<T> x, int h)
{
   if (0 >= h)
      return false; //至多h层
   if (0 < dice(h)) //以1/h的概率终止当前分支的生长
      randomBinTree(bt, bt.insert(x, dice((T)h * h * h)), h - 1);
   if (0 < dice(h)) //以1/h的概率终止当前分支的生长
      randomBinTree(bt, bt.insert(dice((T)h * h * h), x), h - 1);
   return true;
}

// 在二叉树中随机确定一个节点位置
template <typename T>
BinNodePosi<T> randomPosiInBinTree(BinNodePosi<T> root)
{
   if (!HasChild(*root))
      return root;
   if (!HasLChild(*root))
      return dice(6) ? randomPosiInBinTree(root->rc) : root;
   if (!HasRChild(*root))
      return dice(6) ? randomPosiInBinTree(root->lc) : root;
   return dice(2) ? randomPosiInBinTree(root->lc) : randomPosiInBinTree(root->rc);
}

template <typename T>
void testBinTree(int h)
{ //测试二叉树
   printf("\n  ==== Test %2d. Generate a binTree of height <= %d \n", testID++, h);
   BinTree<T> bt;
   // print(bt);
   bt.insert(dice((T)h * h * h));
   // print(bt);
   randomBinTree<T>(bt, bt.root(), h);
   // print(bt);
   printf("\n  ==== Test %2d. Double and increase all nodes by traversal\n", testID++);
   Double<T> db;
   Increase<T> increase;
   bt.travPre(db);
   bt.travPre(increase); // print(bt);
   bt.travIn(db);
   bt.travIn(increase); // print(bt);
   bt.travPost(db);
   bt.travPost(increase); // print(bt);
   bt.travLevel(db);
   bt.travLevel(increase); // print(bt);
   // bt.travLevel(Double<T>());   //函数类作为参数，但c++中临时变量不能作为非const的引用参数
   // bt.travLevel(Increase<T>());
   Hailstone<T> hs;
   bt.travIn(hs);
   // print(bt);
   printf("\n  ==== Test %2d. Remove/release subtrees in the Tree\n", testID++);
   while (!bt.empty())
   {
      BinNodePosi<T> p = randomPosiInBinTree(bt.root()); //随机选择一个节点
      if (dice(2))
      {
         printf("removing ");
         // print(p->data);
         printf(" ...\n");
         printf("%d node(s) removed\n", bt.remove(p));
         // print(bt);
      }
      else
      {
         printf("releasing ");
         // print(p->data);
         printf(" ...\n");
         BinTree<T> *S = bt.secede(p);
         // print(S);
         printf("%d node(s) released\n", S->size());
         release(S);
         // print(bt);
      }
   }
}
}
namespace graph {
/*
// ====================== 生成由v个顶点、e条边构成的随机图 ======================
template <typename Tv, typename Te> //顶点类型、边类型
void randomGraph ( GraphMatrix<Tv, Te> & g, int n, int e ) { 
   while ( ( g.n < n ) || ( g.e < e ) ) { //随机测试
      if ( g.n < n ) { //顶点
         if ( dice ( 100 ) < 65 ) { //65%概率插入顶点
            Tv vertex = ( Tv ) ( 'A' + dice ( 26 ) );      printf ( "Inserting vertex" ); printf ( " ..." );
            g.insert ( vertex );               printf ( "done\n" );
         } else { //35%概率删除顶点
            if ( 1 > g.n ) continue;
            int i = dice ( g.n );       printf ( "Removing vertex %d ...", i );
            Tv v = g.remove ( i );        printf ( "done with" );  printf ( "\n" );
         }
        
      }
      if ( ( 1 < g.n ) && ( g.e < e ) ) { //边
         if ( dice ( 100 ) < 65 ) { //65%概率插入边
            int i = dice ( g.n ), j = dice ( g.n ); Te e = dice ( ( Te ) 3 * n );
            printf ( "Inserting edge (%d, %d) = ", i, j );  printf ( " ..." );
            if ( g.exists ( i, j ) ) {
               printf ( "already exists\n" );
            } else {
               g.insert ( e, e, i, j );     printf ( "done\n" );
            }
         } else { //35%概率删除边
            int i = dice ( g.n ), j = dice ( g.n );
            printf ( "Removing edge (%d, %d) ...", i, j );
            if ( g.exists ( i, j ) ) {
               Te e = g.remove ( i, j );  printf ( "done with" ); printf ( "\n" );
            } else {
              printf ( "not exists\n" );
            }
         }
      }
   }
   for ( int i = 0; i < n; i++ ) g.vertex ( i ) = 'A' + i;
   //print ( g );
}


// ====================== 从命令行（文件重定向）中导入图 ======================
void importGraph ( GraphMatrix<char, int> & g ) {
   int n; scanf ( "%d\n", &n ); printf ( "%d vertices\n", n );
   for ( int i = 0; i < n; i++ ) { //插入v个顶点
      char vertex; scanf ( "%c", &vertex ); printf ( "Inserting vertex" ); printf ( " ..." );
      g.insert ( vertex );                 printf ( "done\n" );
   }
   for ( int i = 0; i < n; i++ )
      for ( int j = 0; j < n; j++ ) { //插入边
         int edge; scanf ( "%d", &edge );
         if ( 0 > edge ) continue;             printf ( "Inserting edge (%d, %d) = ", i, j ); printf ( " ..." );
         g.insert ( edge, edge, i, j );        printf ( "done\n" );
      }
}

void testGraph(void)
{
   srand ( ( unsigned int ) time ( NULL ) );
   GraphMatrix<char, int> g;
   randomGraph<char, int> ( g, 100, 60); //顶点以字符编号，边为整数权重
   //importGraph ( g ); //从命令行（文件重定向）中导入图
   printf ( "\n" ); //print ( g );
   printf ( "=== BFS\n" );
   g.bfs ( 0 ); //print ( g );
   printf ( "=== BFS (PFS)\n" );
   g.pfs ( 0, BfsPU<char, int>() ); //print ( g );
   printf ( "=== DFS\n" );
   g.dfs ( 0 ); //print ( g );
   printf ( "=== DFS (PFS)\n" );
   g.pfs ( 0, DfsPU<char, int>() ); //print ( g );
   printf ( "=== TopoSort\n" );
   Stack<char>* ts = g.tSort ( 0 );  release ( ts );

   printf ( "=== Prim\n" );
   g.prim ( 0 ); //print ( g );
   printf ( "=== Prim (PFS)\n" );
   g.pfs ( 0, PrimPU<char, int>() ); //print ( g );
   printf ( "=== Dijkstra\n" );
   g.dijkstra ( 0 ); //print ( g );
   printf ( "=== Dijkstra (PFS)\n" );
   g.pfs ( 0, DijkPU<char, int>() ); //print ( g );
}
*/
}

#define IsEqual(a, b) ( (a) == (b) )

int main ( int argc, char* argv[] ) 
{
   //stackandqueue::testStackAndQueue();
   //bintree::testBinTree<int>(9); //元素类型可以在这里任意选择
   //graph::testGraph();
   list::testList();

	
   return 0;
}
