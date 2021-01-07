#include<iostream>
#include<string>
#include<vector>
using namespace std;

class stacks
{
	vector<pair<long long,long long> > elements;
	long long top;

public:
	stacks()
	{
		top=-1;
	}
	bool empty()
	{
		return top==-1;
	}
	void push(long long e)
	{
		if(empty())
		{
			elements.push_back(make_pair(e,e));
			top=0;
		}
		else
		{
			long long mx=max(e,elements[top].second);
			elements.push_back(make_pair(e,mx));
			top++;
		}
	}
	void pop()
	{
		elements.pop_back();
		top--;
	}
	long long maxe()
	{
		return elements[top].second;
	}
};

int main()
{	
	long long n;
	cin>>n;
	stacks s;
	string inp;
	long long e,i;
	for(i=0;i<n;++i)
	{
		cin>>inp;
		if(inp=="push")
		{
			cin>>e;
			s.push(e);
		}
		else if(inp=="pop")
			s.pop();
		else
			cout<<s.maxe()<<"\n";
	}
	return 0;
}
