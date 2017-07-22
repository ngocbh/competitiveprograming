s(pos,i,m,j)
{ if ((pos>=i)&&(pos<i+m))
 pos=pos-i+1+j-1;
 else
 { if (pos > i) pos-=m;
   if (pos>=j ) pos+=m;

 }
    return pos;
}
