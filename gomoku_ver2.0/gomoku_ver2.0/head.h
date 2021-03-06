#define FLOOR 8                   //每次更改FLOOR，需要将board.c中的priority, best_score_of_upper, not_in_the_same_branch这三个数组的大小改一下
#define MaxRange 12                   //搜索宽度
#define Consecutive_Five 10000000 //连五
#define Open_Four 2000000         //活四
#define Double_Chess 1000000      //双活三、双冲四、冲四活三等
#define Open_Three 100000         //活三
#define Gapped_Two_Two 100000     //下面三种都是冲四，这种是两个2子之间缺了一个子  ●●？●●
#define Capped_Four 100000        //这种冲四是一头被堵住的冲四   ○●●●●和●●●●○。○●●_●●不算，这个是GappedTwoTwo，○●_●●●
#define Gapped_Four 100000        //这种冲四是一个活三与一个单独的子之间空了一格  ●?●●●，还有这种情况○●●●_●和●_●●●○
#define Gapped_Three 90000        //这种是跳活三，是即将形成活四的三  ●？●●
#define Double_Gapped_Three 100000//这种是双跳活三_●_●●_●_
#define Bad_Six 10000             //有禁手的双跳活三，六腐
#define Capped_Three 1000         //眠三, 最多只能形成冲四  ○●●●
/*眠三一共有这几种形态：
1. ○●●●__
2. ○●●_●_
3. ○●_●●_
4. ●●__●
5. ●_●_●
6. ○_●●●_○
*/
#define Open_two 1000             //连二
#define depth_of_hashing 50331653 //最大是6层，80000023，但是在8层的时候malloc会失败
#define infinity 89999900
                                  //哈希表的容量参考：https://planetmath.org/goodhashtableprimes

typedef struct temp_priority
{
	long int score;
	int raw;
	int column;
	struct temp_priority* next;
} Node;

typedef struct HashElement//新的哈希表的每个单元
{
	unsigned long long hash_value_of_board;
	long int my_value;
	long int opponent_value;
	int floor;
} HE;

typedef struct RootPoint//根节点
{
	int raw;//自己的横坐标
	int column;//自己的纵坐标
	int LeafPoint[MaxRange][2];//所属的10个叶节点的坐标
	int best_leaf[2];//最佳叶节点坐标
}rp;

void initial_board();
void DrawBoard(long int value, int mode_choice, int step_count);
int mode_choose(int mode_choice);
void chess_play_ver2(int step_count);
long int evaluation(int step_count, bool my_turn, int raw, int column);
void return_to_normal_chess(int step_count);
bool judgement(int step_count);
void pvp(long int value);
void get_coordinate(int step_count);
void init_genrand64(unsigned long long seed);
void init_by_array64(unsigned long long init_key[], unsigned long long key_length);
unsigned long long genrand64_int64(void);
int indexOf(int chess);
void initTable();
long int Searching_Hashing(int step_count, bool my_turn, long temp_score, bool write, int floor);
void pve(long int value);
int offensive();
void auto_play(int chess, int opponent_chess);
long int deepest(int step_count, bool my_turn);
long int line(bool state[], int vector[], int raw, int column, int step_count);
void init_best_score_of_upper();
void refresh_score(int step_count, bool my_turn);
void re_calculate(int vector[], int step_count, bool my_turn);
int before_evaluation_ver6(int step_count);
int line_forbid(bool forbid_three[], bool forbid_four[], int vector[], int raw, int column);
bool detect_forbidden_step(int raw, int column);
void open_base();
void randomly_choose_a_point(int raw, int column);
void shallowest2(int step_count, bool my_turn);
long int Minimax4(int step_count, bool my_turn, int floor, int top_floor);
long int iteration_search(int step_count, bool my_turn);
void refresh_banned_point_whole();
void refresh_banned_point_single_line(int vector[]);
bool this_blank_is_useful(int raw, int column, int step_count);
