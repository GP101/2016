# C++ Understanding

Basic C++ Video tutorial on youtube:
https://www.youtube.com/playlist?list=PLrrTotxaO6kiFzuKfSHy3t-zOZNXSGGAE

Advanced C++ Video tutorial on youtube:
https://www.youtube.com/playlist?list=PLrrTotxaO6khn83BjtBN-1HMDc9MZ__yt

### C언어 복습: 구조체와 클래스(structure and class)
  - 개발 환경 준비하기
  - 구조체가 필요한 이유를 이해.
  - 기본적인 구조체 문법의 이해.
  - 구조체의 메모리 할당.
  - 구조체를 파라미터로 전달하는 방법.
  - 구조체의 복사 문제.
  - 구조체에 대한 포인터 사용이 필요한 이유.
  - 구조체를 위한 연산자 .과 ->화살표
  - 멤버 함수를 포함하는 구조체.
  - 구조체 자신을 가리키는 포인터 this.
  - 구조체와 클래스의 차이.
### 생성자와 소멸자(constructor and destructor)
  - 생성자와 소멸자의 기본 개념.
  - 오버로딩 및 explicity의 이해
  - 복사 생성자의 개념 이해.
  - 복사 생성자의 작성.
  - 생성자의 반환값 최적화의 이해.
### 참조(reference)
  - 참조에 대한 기본 이해.
  - 참조에 const를 사용하는 이유.
  - 주소연산자 &와 참조 연산자 &의 이해
  - 주소연산자 & 를 이용한 Swap()의 구현
  - 참조를 리턴하는 함수
  - 멤버 데이터의 참조 선언의 이해.
### 상속과 가상함수(Inheritance and virtual function)
  - 접근 변경자의 종류와 개념의 이해.
  - HAVE-A를 표현하는 세가지 방법의 이해.
  - 오버라이딩의 개념이해와 구현 방법.
  - 파괴자의 호출 순서의 이해와 주의할 점.
  - 가상함수의 기본적인 개념에 대한 이해.
  - 파괴자를 가상으로 선언해야 하는 이유.
  - 가상함수의 내부 동작에 대한 이해.
  - 컴파일러가 vtable을 관리하는 방법.
### 이름공간(namespace)
  - 이름공간의 이해와 사용 방법.
### 연산자 오버로딩(operator overloading)
  - 연산자 오보로딩의 개념 이해.
  - 연산자 오버로딩 함수를 작성하는 방법.
  - ostream에 사용된 연산자 오버로딩의 이해.
  - operator new에 대한 자세한 이해.
  - 동적 메모리 할당의 개념.
### 템플릿(template)
  - 오버로딩과 템플릿에 사용된 이름 장식.
  - 클래스 템플릿의 이해.
  - 템플릿 특화의 이해.
  - 부분 특화와 전체 특화.
  - 템플릿 메타프로그래밍의 이해.
  - 가변 템플릿 함수의 이해와 구현.
  - 가변 템플릿 클래스의 이해와 구현.
  - 형변환 연산자의 역할에 대한 이해.
### 형 변환 연산자(type casting operator)
  - static_cast와 dynamic_cast의 차이점 이해.
### STL의 개념(STL concepts)
  - STL 라이브러리의 개념 이해.
  - 컨테이너와 아이터러터의 개념
  - STL 라이브러리의 간단한 구현.
### decltype의 이해(understanding decltype)
  - decltype 전의 시도들.
  - typeof 매크로의 정의 구현."
  - 형을 대상으로 하는 연산을 해결하는 방법.
  - 템플릿 타입간의 연산에 대한 형 정의.
  - decltype에 꼬리 리턴 타입이 필요한 이유.
### 범위 지정 for문(range-based for-statement)
  - range-based for의 원리
  - C++11 표준에 추가된 range-based for
  - STL 표준 라이브러리에 사용된 base-from-member 관용구의 이해
### STL 커스텀 할당(STL custom allocator)
  - 위치지정 new연산자의 이해
  - rebind의 원리
  - 커스텀 할당자의 제작1/2
  - 커스텀 할당자의 제작2/2
### std::tuple이해하기(understanding std::tuple)
  - make_seq의 구현
  - tuple_helper의 구현
  - std::get의 구현
### 스마트 포인터(smart pointer)
  - std::shared_ptr의 사용법
  - 안전한 참조와 bool 표현식
  - safe-bool 관용구
  - copy-and-swap 관용구
  - swap()과 reset()의 구현
  - safe bool과 explicit
  - 순환 참조를 해결하는 방법
  - 클래스 내부에서 shared_ptr사용하기
### 완전한 전달(perfect forwarding)
  - l-value와 r-value의 이해
  - r-value 참조의 의미
  - 복사 생성자의 이해
  - operator=()과 복사문제
  - 이동 생성자move constructor
  - 완전한 전달
  - remove_reference의 원리
  - std::forward의 이해
### 람다(lambda)
  - 함수 포인터와 함수 객체
  - bind2nd()의 구현
  - std::bind와 람다
  - std::bind의 사용법
  - std::bind를 사용하여 멤버 함수 바인드하기
  - placeholder타입의 역할
  - 람다와 캡쳐 리스트
  - 쓰레드에서 람다의 사용
### 싱글턴(singleton)
  - 싱글턴 1/3
  - 싱글턴 2/3
  - 싱글턴 3/3
### RAII
  - RAII의 의미, STRING_CAT의 구현
  - SCOPE_EXIT의 구현
  - PRE_BLOCK의 구현
