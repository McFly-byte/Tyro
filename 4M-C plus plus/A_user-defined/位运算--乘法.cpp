							//λ�������˷� 
unsigned int mul16(unsigned int x, unsigned int y){

    unsigned int a,b,c;

    unsigned int i;

    a=x;

    b=y;

    c=0;

    for(i=0;i<16;i++){  //�������ͳ����ж���λ������Ҫ�ۼӶ��ٴ�

        if((b&1)==1){ //LSB of b is 1.��b�����λ�Ƿ���1�������1�Ļ�����c���ϱ�����

            c+=a;

        }

        a=a<<1;//shift a 1-bit left

        b=b>>1;//shift b 1-bit right

    }

    return(c); //return product

}

