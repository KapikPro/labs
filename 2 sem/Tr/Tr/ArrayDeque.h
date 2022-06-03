#ifndef ARRAY_DEQUE_
#define ARRAY_DEQUE_

#include <cstdio>  
#include <cstdint> 
#include <cstdlib>
#include <algorithm> 

struct ElemInfo
{
	int number;
	char final_point[64];
	char start_point[64];
	double start_time;
	double travel_time;
	int cost;
};

struct ArrayDeque
{
	ElemInfo* data;
	size_t capacity;
	size_t first;
	size_t last;
};

bool empty(const ArrayDeque& ad)
{
	if (ad.first != 0 && ad.last != 0)
		return false;
	return true;
}

size_t size(const ArrayDeque& ad)
{
	if (ad.data == nullptr)
		return 0;
	if (ad.first > ad.last)
		return ad.capacity - (ad.last - ad.first);
	return ad.last - ad.first;
}

void init(ArrayDeque& ad)
{
	ad.data = (ElemInfo*)malloc(sizeof(ElemInfo));
	ad.capacity = 1;
	ad.first = 0;
	ad.last = 0;
}

void clear(ArrayDeque& ad)
{
	if (ad.data == nullptr)
		return;
	free(ad.data);
	ad.data = nullptr;
	ad.capacity = 0;
	ad.first = 0;
	ad.last = 0;
}

void push_back(ArrayDeque& ad, const ElemInfo& info)
{
	if (size(ad) == ad.capacity)
	{
		ad.capacity *= 2;
		ad.data = (ElemInfo*)realloc(ad.data, ad.capacity * sizeof(ElemInfo));
	}

	if (ad.last == ad.capacity)
		ad.last = 1;
	else
		++ad.last;

	*(ad.data + ad.last - 1) = info;
}

void pop_back(ArrayDeque& ad)
{
	if (size(ad) == 0)
		throw std::logic_error("erorr: пустой дек");

	if (ad.last == 1)
		ad.last = ad.capacity;
	else
		--ad.last;
}

void push_front(ArrayDeque& ad, const ElemInfo& info)
{
	if (size(ad) == ad.capacity)
	{
		ad.capacity *= 2;
		ad.data = (ElemInfo*)realloc(ad.data, ad.capacity);
	}

	if (ad.first == 0)
		ad.first = ad.capacity - 1;
	else
		--ad.first;

	*(ad.data + ad.first) = info;
}

void pop_front(ArrayDeque& ad)
{
	if (size(ad) == 0)
		throw std::logic_error("erorr: пустой дек");

	if (ad.first == ad.capacity - 1)
		ad.first = 0;
	else
		++ad.first;
}

void reverse(ArrayDeque& ad)
{
	std::reverse(ad.data + ad.first, ad.data + ad.last);
}

void print(const ElemInfo& info)
{
	printf("--------------------------------------------\n");
	// С++
	printf("%d\n", info.number);
	printf("%s\n", info.start_point);
	printf("%s\n", info.final_point);
	printf("%4.2lf\n", info.start_time);
	printf("%4.2lf\n", info.travel_time);
	printf("%d\n", info.cost);
	printf("--------------------------------------------\n");
}

void print(const ArrayDeque& ad)
{
	if (empty(ad))
	{
		printf("вы не создали дек или не заполнили..\n");
		return;
	}
	for (size_t i = ad.first; i != ad.last;)
	{
		print(ad.data[i]);

		if (i == ad.capacity - 1)
			i = 0;
		else
			++i;
	}
}
void log(ArrayDeque& ad)
{
	FILE* t;
	if ((t = fopen("log.txt", "a")) == NULL)
	{
		printf("ошибка открытия файла\n");
		exit(0);
	}
	fprintf(t, "|NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN|\n");
	fprintf(t, "|------------------------------------------|\n");
	fprintf(t, "|------------------------------------------|\n");
	fprintf(t, "\nначало дека %p, конец дека %p\n", ad.first, ad.last);

	if (empty(ad))
	{
		fprintf(t, "вы не создали дек или не заполнили..\n");
		return;
	}


	for (size_t i = ad.first; i != ad.last;)
	{
		printf("%d\n", ad.data[i].number);
		printf("%s\n", ad.data[i].start_point);
		printf("%s\n", ad.data[i].final_point);
		printf("%4.2lf\n", ad.data[i].start_time);
		printf("%4.2lf\n", ad.data[i].travel_time);
		printf("%d\n", ad.data[i].cost);
		printf("--------------------------------------------\n");
		if (i == ad.capacity - 1)
			i = 0;
		else
			++i;
	}
	fprintf(t, "|------------------------------------------|\n");
	fprintf(t, "|------------------------------------------|\n");
	fprintf(t, "|KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK|\n");
	fclose(t);
}
void solve(const  ArrayDeque ad1, ArrayDeque& ad2, ArrayDeque& ad3)
{
	if (empty(ad1))
	{
		printf("вы не создали дек или не заполнили, пойдите и исправьте..\n");
		return;
	}

	for (size_t i = ad1.first; i != ad1.last;)
	{
		if (strcmp(uppercase(ad1.data[i].start_point), "МОСКВА") == 0 &&
			strcmp(uppercase(ad1.data[i].final_point), "САНКТ-ПЕТЕРБУРГ") == 0 &&
			ad1.data[i].start_time >= 7.00 && ad1.data[i].start_time <= 9.00)
			push_back(ad2, ad1.data[i]);
		else
			push_back(ad3, ad1.data[i]);
		if (i == ad1.capacity - 1)
			i = 0;
		else
			++i;
	}
	printf("второй дек был заполнен походящими элементами, а третий неподходящими\n");
}
void read_info(ElemInfo& info)
{
	scanf("%d", &info.number);
	scanf("%s", info.start_point);
	scanf("%s", info.final_point);
	scanf("%lf", &info.start_time);
	scanf("%lf", &info.travel_time);
	scanf("%d", &info.cost);
	time_check(info.start_time);
	time_check(info.travel_time);

}
void fread_info(ElemInfo& info, FILE* f)
{
	fscanf(f, "%d", &info.number);
	fscanf(f, "%s", info.start_point);
	fscanf(f, "%s", info.final_point);
	fscanf(f, "%lf", &info.start_time);
	fscanf(f, "%lf", &info.travel_time);
	fscanf(f, "%d", &info.cost);
	time_check(info.start_time);
	time_check(info.travel_time);

}
#endif // ARRAY_DEQUE_