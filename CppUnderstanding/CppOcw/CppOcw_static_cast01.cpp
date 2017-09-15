class KTest
{

};

class KHello
{
};

int main()
{
    KTest* pTest = nullptr;
    KHello* pHello = nullptr;

    pTest = static_cast<KTest*>( pHello ); // compile time error for non related types.
    if( pTest != nullptr )
    {
    }//if
}//main()