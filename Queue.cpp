// Написать программу, релаизующую абстрактный тип данных очередь
// Прототипы функций:
int nextPos(int p); // Функци¤, возвращающа¤ номер следующей позиции
void reset(); // Функци¤, сбрасывающа¤ значение головы и хвоста на начальные
void enqueue(char ch); // Функци¤, помещающа¤ символ в хвост очереди
char dequeue(); // Функци¤, снимающа¤ символ из головы очереди
char front(); // Функци¤, копирующа¤ и возвращающа¤ значение из головы
int full(); // Функци¤, провер¤юща¤, полна¤ ли очередь, возвращает 1 или 0 (правда или ложь)
int empty(); // Функци¤, провер¤юща¤, пуста¤ ли очередь, возвращает 1 или 0 (правда или ложь)
class queue; // Очередь

#include <iostream>
using namespace std;
#define L 10

class queue{
public:
	void reset(); // Функци¤, сбрасывающа¤ значение головы и хвоста на начальные	
	void enqueue(char ch); // Функци¤, помещающа¤ символ в хвост очереди
	char dequeue(); // Функци¤, снимающа¤ символ из головы очереди
	char front() { return s[rear]; } // Функци¤, копирующа¤ и возвращающа¤ значение из головы
	int full() { return (nextPos(nextPos(tail))==rear); } // Функци¤, провер¤юща¤, полна¤ ли очередь, возвращает 1 или 0 (правда или ложь)
	int empty() {  return (nextPos(tail)==rear); } // Функци¤, провер¤юща¤, пуста¤ ли очередь, возвращает 1 или 0 (правда или ложь)
private:
	char s[L];
	int rear, tail;
	int nextPos(int p) { return (p+1)%L; } // Функци¤, возвращающа¤ номер следующей позиции
};

void queue::reset(){ 
	rear=0;
	tail=L-1;
} 

void queue::enqueue(char ch) { 
	tail=nextPos(tail);
	s[tail]=ch;
}

char queue::dequeue(){ 
	char c=s[rear];
	rear=nextPos(rear);
	return c;	
}
	
int main(){
	char str[]="ABCDEFGHIJKLMNOP";
	queue q;
	q.reset();
	int i=0;
	while (!q.full())
		q.enqueue(str[i++]); // Очередь заполн¤етс¤ элементами символьного массива
	while (!q.empty())
		cout<<q.dequeue()<<endl; // Вывод очереди
	return 0;
}
