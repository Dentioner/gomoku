#define FLOOR 8
#define Range 15
//ÿ�θ���FLOOR����Ҫ��board.c�е�priority, best_score_of_upper, not_in_the_same_branch����������Ĵ�С��һ��
#define Consecutive_Five 10000000//����
#define Open_Four 1000000//����
#define Double_Chess 800000//˫������˫���ġ����Ļ�����
#define Open_Three 100050//����
#define Gapped_Two_Two 100000//�������ֶ��ǳ��ģ�����������2��֮��ȱ��һ����  ��񣿡��
#define Capped_Four 100000//���ֳ�����һͷ����ס�ĳ���   ������͡����𡣡���_����㣬�����GappedTwoTwo�����_����
#define Gapped_Four 100000//���ֳ�����һ��������һ����������֮�����һ��  ��?���񣬻���������������_��͡�_�����
#define Gapped_Three 99950//���������������Ǽ����γɻ��ĵ���  �񣿡��
#define Double_Gapped_Three 100020//������˫������_��_���_��_����ֵӦ�ñȳ��ĸ�һ�㣬�Ȼ�����һ��
#define Bad_Six 10000//�н��ֵ�˫������������
#define Capped_Three 50//����, ���ֻ���γɳ���  �����
//��Ҫ�����Ĵ���� ���1000��
/*����һ�����⼸����̬��
1. �����__
2. ����_��_
3. ���_���_
4. ���__��
5. ��_��_��
6. ��_����_��
*/
#define Open_two 5//����
#define depth_of_hashing 80000023
#define infinity 89999900


typedef struct temp_priority
{
	long int score;
	int raw;
	int column;
	struct temp_priority* next;
} Node;

typedef struct HashElement//�µĹ�ϣ���ÿ����Ԫ
{
	unsigned long long hash_value_of_board;
	long int my_value;
	long int opponent_value;
	int floor;
} HE;

typedef struct RootPoint//���ڵ�
{
	int raw;//�Լ��ĺ�����
	int column;//�Լ���������
	int LeafPoint[Range][2];//������10��Ҷ�ڵ������
	int best_leaf[2];//���Ҷ�ڵ�����
}rp;

void myprintf(int array[], int length);
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
void shallowest(int step_count, bool my_turn);
long int line(bool state[], int vector[], int raw, int column, int step_count);
void init_best_score_of_upper();
void refresh_score(int step_count, bool my_turn);
void re_calculate(int vector[], int step_count, bool my_turn);
int before_evaluation_ver6(int step_count);
void quick_sort(long int temp_priority[][3], int l, int r);
int line_forbid(bool forbid_three[], bool forbid_four[], int vector[], int raw, int column);
bool detect_forbidden_step(int raw, int column);
void open_base();
void randomly_choose_a_point(int raw, int column);
void shallowest2(int step_count, bool my_turn);
long int Minimax4(int step_count, bool my_turn, int floor, int top_floor);
long int iteration_search(int step_count, bool my_turn);