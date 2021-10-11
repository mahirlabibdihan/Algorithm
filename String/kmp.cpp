
void LPS(string pat,ll m, vll &lps) 
{ 
	for(i=1,j=0;i<m;i++)pat[j]==pat[i]?lps[i++]=++j:j?j=lps[j-1]:i++; 	
} 

void kmp(string pat,string txt) 
{ 
	m=pat.size(),n=txt.size(); //int c=0;
    vll lps(m); LPS(pat,m,lps);
	for(i=j=0;i<n;) 
	{ 
		pat[j]==txt[i]?i++,++j:j?j=lps[j-1]:i++; 
		if (j == m) 
		{	printf("Found pattern at index %d\n",i-j+1); 
            break;//print the first occurence
			j=lps[j-1];//print all occurence
			//c++;//number of occurences
		} 		
	} 
	//return c;

}