#include<stdio.h>
#include<list>
#include<vector>
// ��1��(10�_)
// �ȉ��̃N���X�ɃR���X�g���N�^�A�f�X�g���N�^��ǉ����Ă��������B
// �R���X�g���N�^�A�f�X�g���N�^�̏����̓��e�͂Ȃ�ł��\���܂���

class Point
{
public:
	Point();
	~Point();
private:
	int x = 0;
	int y = 0;
};
Point::Point()
{
	printf("Test�J�n\n");
}
Point::~Point()
{
	printf("Test�I��\n");
}



// ��2��(10�_)
// int�^�̕ϐ���new���g���m�ۂ��Ă��������B
// �܂��Achar�^�̔z���new���g���m�ۂ��Ă��������B
// �ǂ����delete���Ăяo���悤�ɂ��Ă��������B
int main()
{
	int* newInt = new int;
	char* charArr = new char[5];
	delete newInt;
	delete[] charArr;
}


// ��3��(15�_)
// �ȉ��̌p����N���X�̃f�X�g���N�^���������Ăяo�����悤�ɁA
// �N���X���C�����Ă��������B

class Test
{
public:
	Test()
	{
		printf("Test\n");
	}
	virtual ~Test()
	{
		printf("~Test\n");
	}
};
class Test2 : public Test
{
public:
	Test2()
	{
		printf("Test2\n");
	}
	~Test2()
	{
		printf("~Test2\n");
	}
};
int main()
{
	Test* t;
	t = new Test2();

	delete t;
	return 0;
}


// ��4��(25�_)
// �ȉ��̊֐����e���v���[�g�����āA
// �l�X�Ȍ^�Ōv�Z�ł���悤�ɂ��Ă��������B
template <typename T>
float Calc(T a, T b, int type)
{
	float ans = 0;
	switch (type)
	{
	case 0:
		ans = a + b;
		break;
	case 1:
		ans = a - b;
		break;
	case 2:
		ans = a * b;
		break;
	case 3:
		ans = a / b;
		break;
	}

	return ans;
}
int main()
{
	int ans1;
	float ans2;
	char ans3;

	ans1 = Calc<int>(2, 5, 0);
	printf("%d\n", ans1);
	ans2 = Calc<float>(10.0f, 2.5f, 3);
	printf("%f\n", ans2);
	ans3 = Calc<char>(10, 4, 2);
	printf("%c\n", ans3);

	return 0;
}

// ��5��(25�_)
// ���̃v���O�������C�����A�ȉ��̂悤�ȕ\���ɂȂ�悤�Ƀv���O�������쐬���Ă��������B
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// �܂��A���X�g�̃f�[�^��30�����Ȃ���Ԃɂ��Ă��������B���̍ە\���͈ȉ��̂ɂȂ�܂��B
// num = 30
int main()
{
	std::list<int> lst;
	for (int i = 1; i < 6; ++i)
		// �����Ƀv���O�������L�q
		lst.push_front(i * 10);
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		printf("num = %d\n", *it);
	// ���X�g���C������num=30�ƕ\�������悤�Ƀv���O�������L�q
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end();)
	{
		if (*(it) != 30)
			it = lst.erase(it);
		else
			++it;
	}
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		printf("num = %d\n", *it);
}

// ��6��(25�_)
// ��5��Ɠ����\���ɂȂ�悤��std::vector���g���ăv���O�������L�q���Ă��������B

int main()
{
	std::vector<int> vec;
	for (int i = 5; i > 0; i--)
		vec.push_back(i * 10);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		printf("num = %d\n", *it);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end();)
	{
		if (*(it) != 30)
			it = vec.erase(it);
		else
			++it;
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		printf("num = %d\n", *it);
}