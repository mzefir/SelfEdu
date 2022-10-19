#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

static int ThreadsCreated = 0;

void longTimeOperation()
{
	ThreadsCreated++;
	cout << ThreadsCreated << "-" << this_thread::get_id() << "# BEGIN\n";
	this_thread::sleep_for(chrono::seconds(5));
	cout << ThreadsCreated << "-" << this_thread::get_id() << "# END\n";
}

class Operation
{

public:
	Operation()
	{
		this->id = ThreadsCreated++;
	}

	~Operation()
	{
		cout << "Thread finished: " << this->id << endl;
	}

	void execute()
	{
		cout << ThreadsCreated << "# BEGIN" << endl;
		this_thread::sleep_for(chrono::seconds(5));
		cout << ThreadsCreated << "# END" << endl;
		this->finished = true;
	}

	int id;
	bool finished = false;
};

struct MyThread
{
	Operation op;
	thread* t;

	MyThread(Operation opp, thread* tt)
	{
		op = opp;
		t = tt;
	}

	MyThread(const MyThread& other)
	{
		op = other.op;
		t = other.t;
	}

	bool operator==(const MyThread& other)
	{
		return other.op.id == this->op.id;
	}
};

vector<MyThread *> tasks;


int main()
{
	int maxExecution = 60;
	int maxThreads = 4;
	while (maxExecution > 0)
	{
		if (tasks.size() < maxThreads) {
			maxExecution--;
			Operation op;
			MyThread *my = new MyThread( op, new thread(&Operation::execute, op));
			tasks.push_back(my);
		}

		auto it = tasks.end();
		for (auto& my : tasks)
		{
			if (my->op.finished) {
				my->t->join();
				it = std::find(tasks.begin(), tasks.end(), my);
				break;
			}
		}
		if (it != tasks.end()) {
			tasks.erase(it);
		}
	}
	//Operation op1, op2, op3;
	//tasks.push_back(thread(&Operation::execute, &op1));
	//tasks.push_back(thread(&Operation::execute, &op2));
	//tasks.push_back(thread(&Operation::execute, &op3));

	//cout << "Heloszki\n";

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << "Checking joinable " << i + 1 << "/10" << endl;
	//	for (auto& t : tasks)
	//	{
	//		cout << "joinable?: " << t.joinable() << endl;
	//	}
	//	this_thread::sleep_for(chrono::seconds(1));
	//}
	//
	//for (auto& t : tasks)
	//{
	//	t.join();
	//}

	//this_thread::sleep_for(chrono::seconds(5));

	//cout << endl << "############" << endl;
	return 0;
}