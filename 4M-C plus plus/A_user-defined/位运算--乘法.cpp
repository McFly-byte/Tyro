							//位运算做乘法 
unsigned int mul16(unsigned int x, unsigned int y){

    unsigned int a,b,c;

    unsigned int i;

    a=x;

    b=y;

    c=0;

    for(i=0;i<16;i++){  //被乘数和乘数有多少位，就需要累加多少次

        if((b&1)==1){ //LSB of b is 1.看b的最低位是否是1，如果是1的话，让c加上被乘数

            c+=a;

        }

        a=a<<1;//shift a 1-bit left

        b=b>>1;//shift b 1-bit right

    }

    return(c); //return product

}

