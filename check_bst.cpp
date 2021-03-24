int replace_copy(std::vector<int>& a, int n)
{
    int p1=0, p2=1, k=a.size();
    for (; p2<k; ++p2)
    {
        if (a[p2]!=a[p1])
        {
            p1++;
            a[p1]=a[p2];
        }
    }
    a.resize(p1+1);
    return p1;
}

bool check(int n)
{
    srand(time(NULL));
    bst<int> x;
    std::vector<int> arr(n),arr2(n);
    for (int i=0; i<n; ++i)
    {
        int t=rand();
        x.insert(t);
        arr[i]=t;
        arr2[i]=t;
    }
    std::sort(arr.begin(), arr.end());
    replace_copy(arr,n);
    int g=0;
    for (auto& it:x)
    {
        if (it!=arr[g++])
        {
            std::cout<<"wrong answer\ninput array is:\n";
            for (auto& it2: arr2)
            {
                std::cout<<it2<<" ";
            }
            std::cout<<"tree is\n";
            for (auto& it2:x)
            {
                std::cout<<it2<<" ";
            }
            return false;
        }
    }
    return true;
}