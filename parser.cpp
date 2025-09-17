/*
A -> I = E
E -> P O P | P
O -> + | - | * | / | **
P -> I | L | UI | UL | (E)
U -> + | - | !
I -> C | CI
C -> a | b | ... | y | z
L -> D | DL
D -> 0 | 1 | ... | 8 | 9
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

static bool A(), E(), O(), P(), U(), I(), C(), L(), D();

static string s;
static int i;

int main(void) 
{
    ifstream fin("input.txt");
    string buf;

    while (fin >> buf) 
    {
        s = buf;
        i= 0;

        if (A() && i==s.length()) 
        {
            cout << "The string \""<< buf << "\" is in the language" << endl;
        }
        
        else
        {
            cout << "The string \""<< buf << "\" is not in the language" << endl;
        }
    }

    fin.close();
    return 0;
}

static bool A()
	{
		if (I()) 
		{
			if (i < s.length() && (s[i] == '=')) 
			{
				++i;
				if (E()) 
				{
					return true;
				}
				
				return false;
			}
		}
			
		return false;
	}
	
	static bool E()
	{
		if (!P())
		{
			return false;
		}
			
			while (i < s.length())
			{
				int pos = i;
				
				if (O())
				{
					if (!P())
					{
						i = pos;
						return false;
					}
							
				}
				
				else
				{
					break;
				}
			}
			
		return true;
	}
	
	static bool O()
	{
		
		if (i+1<s.length() && s[i]=='*' && s[i+1]=='*')
		{
			i+=2;
			return true;
		}
		
		if (i<s.length() && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'))
		{
			++i;
			return true;
		}
		
		return false;	
	}
	
	static bool P()
	{	
		int pos = i;
		
		if (I())
		{
			return true;
		}
		
		i = pos;
		
		if (L())
		{
			return true;
		}
		
		i = pos;
		
		if (U() && I())
		{
			return true;
		}
		
		i = pos;
		
		if (U() && L())
		{
			return true;
		}
		
		i = pos;
		
		if (i < s.length() && s[i] == '(') 
		{
			++i;
			if (E()) 
			{
				if (i < s.length() && s[i] == ')') 
				{
					++i;
					return true;
				}
			}
		}
		
		i = pos;
		return false;
	}
	
	static bool U()
	{
		if (i<s.length() && (s[i]=='+' || s[i]=='-' || s[i]=='!'))
		{
			++i;
			return true;
		}
		
		return false;
	}
	
	static bool I()
	{	
		int pos = i;
		
		if (C())
		{
			if (i<s.length() && isalpha(s[i]))
			{
				return I();
			}
			
			return true;
		}
		
		i = pos;	
		return false;
	}
	
	static bool C()
	{
		if (i < s.length() && 'a' <= s[i] && s[i] <= 'z') 
		{
			++i;
			return true;
		}
		
		return false;
	}
	
	static bool L()
	{
		int pos = i;
		
		if (D())
		{
			if (i<s.length() && isdigit(s[i]))
			{
				return L();
			}
			
			return true;
		}
			
		i = pos;
		return false;
	}
	
	static bool D()
	{
		if (i < s.length() && '0' <= s[i] && s[i] <= '9') 
		{
			++i;
			return true;
		}
		
		return false;

	}
