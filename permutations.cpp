vb visited(MAX);
void permute(vll x,vll y)
{

   if(sz(y)==n) {v_out(y);}
   else
   {
      for(int i=0;i<n;i++)
      {
      	if(visited[i]) continue;
      	visited[i]=true; y.pb(x[i]);
      	permute(x,y);
      	visited[i]=false; y.p_b;
      }
   }
}