#pragma once
#ifndef _KPREBLOCK_H
#define _KPREBLOCK_H

#include <boost/preprocessor/cat.hpp>

#pragma warning( disable: 4003 ) // 매크로의 실제 매개 변수가 부족합니다.

#ifndef CONSTRUCTOR
#define CONSTRUCTOR
#endif // #ifndef CONSTRUCTOR

#ifndef DESTRUCTOR
#define DESTRUCTOR
#endif // #ifndef DESTRUCTOR

namespace kog
{
    /** @class  KPreBlockVariable
        @desc   if문 안에서 선언한 변수의 선언이 항상 false가 되는 것을 보장하기 위해,
                대상 type을 wrap하는 클래스이다.
                대상 타입 T에 대해, KPreBlockVariable<T>는 항상 false를 리턴하므로,
                ( @see unspecified_bool_type )
                if문안에서 모든 타입의 변수를 자유롭게 선언하면서 초기화하는 것이 가능하다.
                - jintaeks on 2010-12-31, 13:47 */
    template<typename T>
    class KPreBlockVariable : private boost::noncopyable
    {
    private:

        typedef KPreBlockVariable<T>
                        this_type;

    public:

        struct KNoInitialization
        {
        };//struct KNoInitialization

        CONSTRUCTOR     KPreBlockVariable( KNoInitialization ) {}

        CONSTRUCTOR     KPreBlockVariable( const T& In_ ) : m_var( In_ ) {}

        template<typename U>
        CONSTRUCTOR     KPreBlockVariable( U& In_ ) : m_var( In_ ) {}

        typedef void    ( this_type::*unspecified_bool_type )() const;
        /** 정의되지 않은 bool 타입의 conversion에 대해서 이 연산자 함수가 호출될 것이다.
            'unspecified_bool_type'은 항상 false를 리턴하므로, bool 조건은 항상 실패할 것이다.
            예를 들면 아래와 같은 문장이 있다면, 변수는 선언되지만 문장 자체가 false로 evaluation 되므로
            if문의 조건 검사는 실패할 것이다.
                @code
                    if( kog::KPreBlockVariable< TYPE > KLOCALVAR_DECLARE(VAR ) = ( __VA_ARGS__) ) else
                @endcode
            이것은 변수를 선언하면서 이어지는 else if를 계속해서 수행하도록 한다.
            이것은 KPREBLOCK_DECLARE를 연속되게 사용해도 되는 이유이다.
            - jintaeks on 2010-12-31, 13:50 */
        /*bool*/        operator unspecified_bool_type () const { return false; }

        T&              Access() { return m_var; }

        const T&        Get() const { return m_var; }

    private:

        T               m_var;
    };//

    template<typename T>
    class KPreBlockVariable< T& > : private boost::noncopyable
    {
    private:

        typedef KPreBlockVariable< T& >
                        this_type;

    public:

        CONSTRUCTOR     KPreBlockVariable( const T& In_ ) : m_var( In_ ) {}
        template<typename U>
        CONSTRUCTOR     KPreBlockVariable( U& In_ ) : m_var( In_ ) {}

        typedef void    ( this_type::*unspecified_bool_type )() const;
        /*bool*/        operator unspecified_bool_type () const { return false; }

        T&              Access() { return m_var; }

        const T&        Get() const { return m_var; }

    private:

        T&              m_var;
    };//

    template<typename T>
    class KPreBlockVariable< const T& > : private boost::noncopyable
    {
    private:

        typedef KPreBlockVariable< const T& >
                        this_type;

    public:

        CONSTRUCTOR     KPreBlockVariable( const T& In_ ) : m_var( In_ ) {}
        template<typename U>
        CONSTRUCTOR     KPreBlockVariable( U& In_ ) : m_var( In_ ) {}

        typedef void    ( this_type::*unspecified_bool_type )() const;
        /*bool*/        operator unspecified_bool_type () const { return false; }

        const T&        Access() { return m_var; }

        const T&        Get() const { return m_var; }

    private:

        const T&        m_var;
    };//


    template<typename T>
    inline T&           KPreBlockVariableAccess( T& InOut_ )  { return InOut_; }

    template<typename T>
    inline T&           KPreBlockVariableAccess( KPreBlockVariable<T>& InOut_ ) { return InOut_.Access(); }

    template<typename T>
    inline T&           KPreBlockVariableAccess( KPreBlockVariable<T&>& InOut_ ) { return InOut_.Access(); }

    // commented out to resolve Vs2010 ambiguity error by jintaeks on 2011-09-01
    //template<typename T>
    //inline const T&     KPreBlockVariableAccess( KPreBlockVariable<const T>& InOut_ ) { return InOut_.Access(); }

    template<typename T>
    inline const T&     KPreBlockVariableAccess( KPreBlockVariable<const T&>& InOut_ ) { return InOut_.Access(); }
};//namespace   kog


/** @define KCOMMA()
    @brief 매크로 파라미터 안에서 ', ' 대신 사용
    @code std::map<int, int> @endcode 와 같이 ', '가 포함된 타입은 매크로 파라미터로 바로 넘길 수 없다. 이런 경우
    @code std::map<int KCOMMA() int> @endcode 와 같이 넘겨준다. 이보다 더 좋은 방법은
    @code typedef std::map<int, int> KMapIntInt; @endcode 로 타입을 정의한 후 \c KMapIntInt 을 넘기는 것이다.
*/
#ifndef KCOMMA
#define KCOMMA()   ,
#endif // #ifndef KCOMMA

#if defined(_MSC_VER ) && ( _MSC_VER >= 1400 )

#ifndef KARG
#define KARG( ... )  __VA_ARGS__
#endif // #ifndef KTYPE

#else

#ifndef KARG
#define KARG( x )   x
#endif // #ifndef KARG

#endif // #if defined(_MSC_VER ) && ( _MSC_VER >= 1400 )

#if defined( _MSC_VER )

#define KLOCALVAR_DECLARE( x )       BOOST_PP_CAT( $KLOCALVAR$, x )

#else

#define KLOCALVAR_DECLARE( x )       BOOST_PP_CAT( __KLOCALVAR__, x )

#endif // #if defined( _MSC_VER )


#define KLOCALVAR( x )      kog::KPreBlockVariableAccess( KLOCALVAR_DECLARE( x ) )


#define KPREBLOCK_STATEMENT( STATEMENT ) \
    if( ( STATEMENT ), false ) {} \
    else

#define KPREBLOCK_DECLARE( TYPE, VAR ) \
    if( kog::KPreBlockVariable< TYPE > KLOCALVAR_DECLARE( VAR ) = kog::KPreBlockVariable< TYPE >::KNoInitialization() ) {} \
    else

#if defined(_MSC_VER ) && ( _MSC_VER >= 1400 )

#define KPREBLOCK_DECLARE_INITIALIZE( TYPE, VAR, ... ) \
    if( kog::KPreBlockVariable< TYPE > KLOCALVAR_DECLARE( VAR ) = ( __VA_ARGS__ ) ) {} \
    else

/** KPREBLOCK_BLOCK()이 for문을 사용하는 이유는,
    블록 내부에서 break로 블록을 탈출하는 것을 가능하게 하기 위해서이다.
    - jintaeks on 2012-09-21, 12:03 */
#define KPREBLOCK_BLOCK( ... ) \
    if( bool KLOCALVAR_DECLARE( _KPREBLOCK_BLOCK_stop_ ) = false ) {} \
    else \
    for( __VA_ARGS__; KLOCALVAR( _KPREBLOCK_BLOCK_stop_ ) == false; KLOCALVAR( _KPREBLOCK_BLOCK_stop_ ) = true )

#else

#define KPREBLOCK_DECLARE_INITIALIZE( TYPE, VAR, INITVALUE ) \
    if( kog::KPreBlockVariable< TYPE > KLOCALVAR_DECLARE( VAR ) = ( INITVALUE ) ) {} \
    else

#define KPREBLOCK_BLOCK( STATEMENT ) \
    if( bool KLOCALVAR_DECLARE( _KPREBLOCK_BLOCK_stop_ ) = false ) {} else \
    for( STATEMENT; KLOCALVAR( _KPREBLOCK_BLOCK_stop_ ) == false; KLOCALVAR( _KPREBLOCK_BLOCK_stop_ ) = true )

#endif // #if defined( _MSC_VER )


template<typename A>
inline BYTE     KPREBLOCK_IsConst_Dummy( A& )         { return 0; }

template<typename A>
inline WORD     KPREBLOCK_IsConst_Dummy( const A& )    { return 0; }

#define KPREBLOCK_IS_CONST( _variable_ )   ( sizeof( KPREBLOCK_IsConst_Dummy( _variable_ ) ) == sizeof( WORD ) )


using   namespace kog;

/** @example KPreBlock.h

@code

    KPREBLOCK_DECLARE_INITIALIZE( int, i, 3 )
    KPREBLOCK_DECLARE_INITIALIZE( float, f, 2.0f )
    if( FILE* pFile = fopen( "test.txt", "t" ) )
    {
        fprintf( pFile, "%d\n", KLOCALVAR( i ) );
        fprintf( pFile, "%f\n", KLOCALVAR( f ) );
        fclose( pFile );
    }//if


    KPREBLOCK_DECLARE_INITIALIZE( int, i, 3 )
    KPREBLOCK_DECLARE_INITIALIZE( float, f, 2.0f )
    KPREBLOCK_BLOCK( std::vector<int> a )
    {
        a.push_back( KLOCALVAR( i ) );
        a.push_back( ( int ) KLOCALVAR( f ) );
    }

@endcode

*/

#endif // #ifndef _KPREBLOCK_H