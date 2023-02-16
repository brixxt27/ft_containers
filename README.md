# 전체 이슈 List: [Issue "To do"#1](https://github.com/brixxt27/ft_containers/issues/1)
# References
- gcc complier, c++98 vector: https://github.com/gcc-mirror/gcc/blob/54c1bf7801758caf2ff54917e79a8c239643061c/libstdc%2B%2B-v3/include/bits/stl_vector.h
- sfinae, enable_if, 모두의코드: https://modoocode.com/255
- yongmkim, exception safety: https://github.com/ecole42-yoma/ft_containers/wiki/Exception-Safety#classification
- Red–black tree: https://assortrock.com/87
- EA sports STL:  https://github.com/electronicarts/EASTL

# Keyword
- explicit specifier: 생성자가 명시적임을 지정한다. 즉, implicit conversions 와 copy-initialization 을 사용할 수 없다. explicit 지정자를 사용하지 않고 선언한 생성자는 converting constructor 를 호출한다.
https://en.cppreference.com/w/cpp/language/explicit

- implicit conversion: 암시적 형변환은 어떤 타입 T1 의 표현이 문맥에서 다른 타입을 허용하지 않지만, T2 를 허용할 때 발생된다.
https://en.cppreference.com/w/cpp/language/implicit_conversion

- copy-initialization: 다른 object로부터 하나의 object를 초기화한다. copy initialization 은 explicit constructor 를 고려하지 못한다.
```
Syntax
T object = other;	(1)	
T object = {other};	(2)	(until C++11)
f(other)	(3)	
return other;	(4)	
throw object;
catch (T object) (5)	
T array[N] = {other-sequence};	(6)	

ex1)
T object = other;

ex2)
struct Exp { explicit Exp(const char*) {} }; // not convertible from const char*
Exp e1("abc");  // OK
Exp e2 = "abc"; // Error, copy-initialization does not consider explicit constructor
 
struct Imp { Imp(const char*) {} }; // convertible from const char*
Imp i1("abc");  // OK
Imp i2 = "abc"; // OK
```
https://en.cppreference.com/w/cpp/language/copy_initialization

- Converting contructor: explicit 지정자를 사용하지 않고 선언한 생성자는 converting constructor 를 호출한다.
https://en.cppreference.com/w/cpp/language/converting_constructor


# ft_containers
## C++ containers, easy mode
 Summay: 표준 C++ Containers 에 모든 구체적인 사용법이 있다. 너가 이들을 이해했는지를 확인하기 위하여, 이들을 다시 구현해보자! - Version: 5.2

## Contents
1. Objectives
2. General rules
3. Mandatory part
	3.1 요구 사항
	3.2 테스트
4. 보너스 파트
5. 제출 및 동료 학습

## Chapter 1: Objectives
- 이번 프로젝트에서, 넌 몇 개의 C++ 표준 템플릿 라이브러리 container types 을 구현하게 될거야.
- 넌 레퍼런스에서 각각의 표준 컨테이너의 구조를 공부해야 해. 만약 Orthodox Canonical form 파트가 비어 있다면, 그것을 구현하지마.
- 되새김 하자면, 넌 C++98 표준을 준수해야 하고, 컨테이너의 어떠한 이후 기능이든 구현 되어서는 안 되지만, 모든 C++98 기능은(심지어 없어졌더라도) 구현이 필요합니다.

## Chapter 2: General rules
### Compiling
- c++ 과 -Wall -Wextra -Werror 로 컴파일 되어야 한다.
- -std=c++98 flag 를 추가하더라도 너의 코드는 여전히 컴파일 되어야 한다.
- 너의 소스 코드를 컴파일하는 Makefile 을 제출해야하고, Makefile 은 relink 되면 안 된다.
- 너의 Makefile 은 최소한 다음 규칙을 포함해야 한다:
	- &(NAME), all, clean, fclean and re.

### Formatting and naming conventions
- 각 컨테이너는 적절한 이름의 클래스 파일들로 구성되어야 한다.
- 안녕 Norminette! 코딩 스타일은 강제적이지 않아. 너는 너가 좋아하는 스타일을 사용할 수 있어. 그러나 동료평가에서 이해할 수 없는 코드는 점수를 받을 수 없다는 것을 명심해! 너가 할 수 있는 최대한 깔끔하고, 읽기 좋은 코드를 작성해.

### Allowed / Forbidden
- 너는 더 이상 C 로 코딩하지 않아. C++ 로 코딩할 시간이야!
- 넌 표준 라이브러리의 모든 것을 사용할 수 있어. 이미 너가 알고 있는 엄격한 것 대신에 이전에 사용하던 C 함수의 C++스러운 버전을 가능한 더 많이 현명하게 사용하라는 이야기야.
- 그러나 넌 다른 외부의 라이브러리를 사용할 수는 없어. 그건 C++11 과 Boost 라이브러리는 금지되었다는 뜻이다. 이 다음에 오는 함수는 사용하지 마: *printf(), *alloc() 그리고 free(). 만약 이들을 사용한다면 0점을 받을 거야!

### A few design requirements
- 메모리 누수는 C++에서도 발생해. 메모리 할당을 할 때 넌 메모리 누수를 피해야 해.
- 함수 구현을 헤더 파일에 넣는다는 것은(Template를 제외하고) 0점을 받는 다는 걸 의미한다.
- 각 헤더 파일들을 다른 것들과 독립적으로 사용할 수 있어야 한다. 따라서 필요한 모든 의존성을 포함해야 한다. 그러나 include 가드를 사용함으로써 double inclusion 을 피해야 한다. 그렇지 않으면 0점이다.

### Read me
- 넌 추가적인 파일을 추가할 수 있어(즉, 코드를 나눠서). 그리고 Mandatory 파일을 넣은 한 원하는대로 파일을 구성할 수 있어.
- Odin, Thor 의 힘으로! 머리를 써봐!

### <i><b> 이번 과제는 STL containers 를 재구현 하는 일이므로 이들을 사용해서는 안 된다. </b></i>
<br>
<br>

## Chapter 3: Mandatory part
### 다음 오는 컨테이너들을 구현하고, Makefile과 요구되는 {container}.hpp 파일을 넣어라.
- vector
	- vector<'bool> 을 특수화하는 것은 하지 말아라.
- map
- stack
	- vector 클래스를 기본으로 사용한다. 그러나 여전히 STL에 있는 다른 컨테이너와 호환되어야 한다. 

<b> stack을 구현하지 않아도 과제를 통과할 수 있다. 그러나 보너스를 위해선 세 개의 필수 파트 모두를 구현해야 한다. </b>

### 또 아래 따라오는 것들을 구현해야 한다.
- std::iterator_traits
- std::reverse_iterator
- std::enalbe_if
	- 맞아! 이건 C++11이야. 그러나 C++98 식으로 구현할 수 있어. 이건 너가 SFINAE 에 대해 공부할 수 있도록 해줄거야.
- std::is_integral
- std::equal 그리고/또는 std::lexicographical_compare
- std::pair
- std::make_pair

### Requirements
- namespace 는 ft 여야 한다.
- 너의 컨테이너에서 사용되는 각 내부 데이터 구조는 논리적이고, 합당해야 한다.(이건 map 을 구현할 때 간단한 배열을 사용하면 안 된다는 의미이다)
- 넌 표준 컨테이너에서 제공되는 public 함수보다 더 많은 것을 구현할 수 없다. 이를 제외한 모든 것은 private 나 protected여야 한다. 각 public function 또는 변수는 합당한 이유를 가지고 있어야 한다.
- 모든 표준 컨테이너의 member function, non-member function 그리고 overloads 로 예상된다.
- 원본 이름을 사용해야한다. 주의를 기울여줘!
- 만약 컨테이너가 iterator 시스템을 갖고 있다면, 그것을 구현해야 해.
- std::allocator 를 사용해야 한다.
- non-member overloads 는 friend 키워드를 허용한다. 이를 사용한다면 합당한 이유가 있어야 하고, 이는 평가에서 확인될 거야.
- 물론 std::map::value_compare 의 구현은 friend 가 허용되어 있어.

<b> You can use https://www.cplusplus.com/
and https://cppreference.com/ as references. </b>

### Testing
- 평가 시간에 최소 main.cpp 를 포함하는 테스트 코드를 제공해야 한다. 주어진 main 보다 더 많은 예를 넣어줘!
- 너는 두 개의 binary 파일을 생성해야 해: 하나는 너가 만든 containers, 다른 하나는 STL containers
- 출력과 성능 / 시간(원본보다 20% 느릴 수 있다)을 비교해라.
- ft::<'container> 로 테스트해라.

<b> main.cpp 는 intra 프로젝트 페이지에서 다운로드 가능하다. </b>

## Chapter 4: Bonus part
- 추가 점수를 얻기 위해 마지막 하나의 container를 구현해야 한다.
	- set: 그러나 이번엔 Red-Black tree 를 구현해야 한다.

<img width="741" alt="image" src="https://user-images.githubusercontent.com/83959536/215407535-3601155b-f2e5-40ec-9b97-1bae78c1fe71.png">
(레퍼런스의 레드블랙트리 블로그 참고)
