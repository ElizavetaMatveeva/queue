// Написать программу, релаизующую абстрактный тип данных очередь

#include <iostream>
using namespace std;
#define L 10

class queue{
public:
	void reset(); // Функция, сбрасывающая значение головы и хвоста на начальные	
	void enqueue(char ch); // Функция, помещающая символ в хвост очереди
	char dequeue(); // Функция, снимающая символ из головы очереди
	char front() { return s[front]; } // Функция, копирующая и возвращающая значение из головы
	int full() { return (nextPos(nextPos(tail))==front); } // Функция, проверяющая, полная ли очередь, возвращает 1 или 0 
	int empty() {  return (nextPos(tail)==front); } // Функция, проверяющая, пустая ли очередь, возвращает 1 или 0 
private:
	char s[L];
	int front, tail;
	int nextPos(int p) { return (p+1)%L; } // Функция, возвращающая номер следующей позиции
};

void queue::reset(){ 
	front=0;
	tail=L-1;
} 

void queue::enqueue(char ch) { 
	tail=nextPos(tail);
	s[tail]=ch;
}

char queue::dequeue(){ 
	char c=s[front];
	front=nextPos(front);
	return c;	
}
	
int main(){
	char str[]="ABCDEFGHIJKLMNOP";
	queue q;
	q.reset();
	int i=0;
	while (!q.full())
		q.enqueue(str[i++]); // Очередь заполняется элементами символьного массива
	while (!q.empty())
		cout<<q.dequeue()<<endl; // Вывод очереди
	return 0;
}
