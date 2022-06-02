#ifndef LINKED_DEQUE_
#define LINKED_DEQUE_

#include <cstdlib>
#include <cstdint> 
#include <stdexcept> 

struct NodeInfo
{
	int number, cost;
	char final_point[64], start_point[64];
	double travel_time, start_time;
};

struct DequeNode
{
	NodeInfo info;
	DequeNode* next = nullptr;
	DequeNode* prev = nullptr;
};

struct LinkedDeque
{
	DequeNode* first = nullptr;
	DequeNode* last = nullptr;
};

void init(LinkedDeque& ld)
{
	ld.first = nullptr;
	ld.last = nullptr;
}

bool empty(const LinkedDeque& ld)
{
	if (ld.first!=nullptr && ld.last!=nullptr)
		return false;
	return true;
}

void push_back(LinkedDeque& ld, const NodeInfo& info)
{
	auto new_node = (DequeNode*)malloc(sizeof(DequeNode));
	new_node->info = info;

	if (empty(ld))
	{
		ld.first = ld.last = new_node;
	}
	else
	{
		new_node->prev = ld.last;
		ld.last->next = new_node;
		ld.last = new_node;
	}
}

void pop_back(LinkedDeque& ld)
{
	if (empty(ld))
		throw std::logic_error("erorr: пустой дек");

	auto new_last = ld.last->prev;
	free(ld.last);
	ld.last = new_last;
}

void push_front(LinkedDeque& ld, const NodeInfo& info)
{
	auto new_node = (DequeNode*)malloc(sizeof(DequeNode));
	new_node->info = info;

	if (empty(ld))
	{
		ld.first = ld.last = new_node;
	}
	else
	{
		new_node->next = ld.first;
		ld.first->prev = new_node;
		ld.first = new_node;
	}
}
void pop_front(LinkedDeque& ld)
{
	if (empty(ld))
		throw std::logic_error("erorr: пустой дек");

	auto new_first = ld.first->next;
	free(ld.first);
	ld.first = new_first;
}

void clear(LinkedDeque& ld)
{
	while (!empty(ld))
		pop_back(ld);

	ld.first = nullptr;
	ld.last = nullptr;
}
void fread_info(NodeInfo& info)
{
	FILE* f;
	if ((f = fopen("fin.txt", "r")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}
	fscanf(f, "%d", &info.number);
	fscanf(f, "%s", info.start_point);
	fscanf(f, "%s", info.final_point);
	fscanf(f, "%lf", &info.start_time);
	fscanf(f, "%lf", &info.travel_time);
	fscanf(f, "%d", &info.cost);
	fclose(f);
}
void read_info(NodeInfo& info)
{
	scanf("%d", &info.number);
	scanf("%s", info.start_point);
	scanf("%s", info.final_point);
	scanf("%lf", &info.start_time);
	scanf("%lf", &info.travel_time);
	scanf("%d", &info.cost);
}

void log(LinkedDeque& ld)
{
	FILE* f;
	if ((f = fopen("log.txt", "w")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}

	printf("%p %p\n", ld.first, ld.last);
}
void print(const LinkedDeque& ld)
{
	int c = 0;
	if (empty(ld))
	{
		printf("вы не создали стек или не заполнили, пойдите и исправьте..\n");
		return;
	}
	auto cur_node = ld.first;
	printf("\n", c);
	while (cur_node)
	{
		printf("--------------------------------------------\n");
		printf("%dый элемент\n",c);
		c++;
		printf("%d\n", cur_node->info.number);
		printf("%s\n", cur_node->info.start_point);
		printf("%s\n", cur_node->info.final_point);
		printf("%lf\n", cur_node->info.start_time);
		printf("%lf\n", cur_node->info.travel_time);
		printf("%d\n", cur_node->info.cost);
		printf("--------------------------------------------\n");
		cur_node = cur_node->next;
	}
	printf("\n", c);
}

#endif // LINKED_DEQUE_