#include <string>
#include <vector>
#include <map>
#include <deque>
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <list>

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include <stdarg.h>
#include <string.h>

#define P(x) cout << x << endl;

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
};

template <typename T>
void print(T v)
{
	cout << v << endl;
}

template <typename T>
void print(vector<T> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == arr.size() - 1)
		{
			cout << arr[i];
		}
		else
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

template <typename T>
void print(vector<vector<T>> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			if (j == arr[i].size() - 1)
			{
				cout << arr[i][j];
			}
			else
			{
				cout << arr[i][j] << " ";
			}
		}
		if (i != arr.size() - 1)
		{
			cout << ",";
		}
	}
	cout << endl;
}

template <typename T>
void print(T *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename Arg, typename... Args>
void print(Arg &&arg, Args &&... args)
{
	cout << std::forward<Arg>(arg);
	using expander = int[];
	(void)expander{0, (void(cout << ',' << std::forward<Args>(args)), 0)...};
	cout << endl;
}

void print(ListNode *l)
{
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

void plinklist(ListNode *l)
{
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

template <typename T>
vector<T> rd_vec()
{
	// read a line
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;
	// set ans
	vector<T> ans;
	T buf;
	while (ss >> buf)
	{
		ans.push_back(buf);
	}
	return ans;
}

template <typename T>
vector<vector<T>> rd_vec_vec()
{
	vector<vector<T>> ansans;
	string str;
	do
	{
		// read a line
		stringstream ss;
		getline(cin, str);
		ss << str;
		// set ans
		vector<T> ans;
		T buf;
		while (ss >> buf)
		{
			ans.push_back(buf);
		}
		ansans.push_back(ans);
	} while (!str.empty());
	return ansans;
}

ListNode *rd_list()
{
	// read a line
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;
	// set ans
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	int buf;
	while (ss >> buf)
	{
		t->next = new ListNode(buf);
		t = t->next;
	}
	return head->next;
}

template <typename T>
T rd_val()
{
	// read a line
	stringstream ss;
	string str;
	getline(cin, str);
	ss << str;
	// set ans
	vector<T> ans;
	T buf;
	ss >> buf;
	return buf;
}

template <typename T>
T *rd_arr(int *size)
{
	// read a line
	stringstream ss;
	string str;
	vector<T> ans = rd_vec<T>();
	*size = ans.size();
	T *arr = new T[ans.size()];
	for (int i = 0; i < ans.size(); ++i)
	{
		arr[i] = ans[i];
	}
	return arr;
}

ListNode *conv_list(vector<int> ans)
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	for (auto buf : ans)
	{
		t->next = new ListNode(buf);
		t = t->next;
	}
	return head->next;
}

/*
int main(){
    string a, b;
    cin >> a >> b;
    // 读一个值
    float f = rd_val<float>();
    // 读一个数组
    vector<string> v1 = rd_vec<string>();
    // 读一个c数组
    int final_size;
    int *iarr = rd_arr<int>(&final_size);
    // 读一个链表
    ListNode *head = rd_list();

    // 打印一个值
    P(function1(a, b));
    // 打印一个值
    print(f);
    // 打印一个c数组
    print(iarr, final_size);
    // 打印一个数组
    print(v1);
    // 打印一个链表
    plinklist(head);
    return 0;
}
*/