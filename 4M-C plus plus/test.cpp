#import <iostream> 
main() { 
    __int64 n,k,a['   '],d; 
     for(std::cin>>n>>k,n*=2;d<2+k%n*2;a[d%2]=2*a[(d-2)%n+2]-a[d++%2]) std::cin>>a[d]; 
     std::cout<<*a<<" "<<a[1]; 
}
