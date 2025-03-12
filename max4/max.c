int		max(int* tab, unsigned int len)
{
    int max = tab[0];
   unsigned int i = 1;
   if(!tab)
   {
     return(0);
   }
    while(len > i)
    {
        if(max < tab[i])
        {
            max = tab[i];
        }
        i++;
    }
    return(max);
}