 unsigned char        reverse_bits(unsigned char octet)
{
        unsigned char        res = 0;
        int i = 8;

        while (i > 0)
        {
                res = res * 2 + (octet % 2);
                octet = octet / 2;
                i--;
        }
        return (res);
}

///////////////////////

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char res = 0;

    for (int i = 0; i < 8; i++, octet>>=1)
    {
        res = (res << 1) | (octet & 1);
        ////octet >>= 1;
    }
    return res;
}

////////////////////////////////
unsigned char reverse_bits(unsigned char octet)
{
    unsigned char res = 0;

    for (int i = 0; i < 8; i++)
    {
        res = res * 2 + (octet % 2);
        octet = octet / 2;
    }
    return res;
}
