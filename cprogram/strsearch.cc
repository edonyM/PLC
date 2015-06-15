#include <iostream>
#include <cstring>

using namespace std;

//int i=0;
int count_asterisks(char *str)
{
	int asterisk_count = 0;
	for(int x=0; x<strlen(str); x++)
	{
        if(str[x] == '*' && (x == 0 || str[x-1] != '\\'))
		{
			asterisk_count++;
		}
	}
	return asterisk_count;
}
bool match_within(char *, char *);

bool match_at_front(char * search_in, char * search_for)
{
	if(search_for[0] == '\0') //everything matches
	{
		return true;
	}
	else if(search_in[0] == '\0') //end of first string
	{
		return false;
	}
	else if(search_for[0] == '*')
	{  //any number of initial characters are chewed up by the *
	    return match_within(search_in, (search_for+1));
	}
	else if(search_for[0] == '\\' && search_for[1] == '*')
	{
		if(search_in[0] == '*')
		{
			return match_at_front(search_in + 1, search_for + 2);
		}
		else 
		{
			return false;
		}
	}
	else if(search_for[0] == search_in[0])
	{
		return match_at_front(search_in+1, search_for+1);
	}
	else
	{
		return false;
	}
}

bool match_within(char * search_in, char * search_for)
{
	for(int x=0; 
	    x<=strlen(search_in)-strlen(search_for)-count_asterisks(search_for); x++)
	{
        //i++;
        //cout << "counter: " << i << endl;
        //cout << search_in+x << endl;
        //cout << search_for << endl;
		if(match_at_front(search_in+x, search_for))
		{
			return true;
		}
	}
	return false;
}					
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout<<"Input should be of the form substring str1 str2";
		return 0;
	}
    if(match_within(argv[1], argv[2]))
    {
        cout<<"String "<<argv[2];
        cout<<" is contained within "<<argv[1]<<".";
    }
    else
    {
        cout<<"String "<<argv[2]<<" is not contained within ";
        cout<<argv[1]<<".";
    }
}
