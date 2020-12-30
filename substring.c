int find(char x[],char y[])
{
    int p=strlen(x),q=strlen(y),j,k,c=0;

    for(j=0; j<=p-q; j++)
    {
        for(k=0; k<q; k++)

            if(y[k]!=x[k+j])  break;

        if(k==q)  c++;
    }
    return c;
}
