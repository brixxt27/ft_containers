# 전체 이슈 List: [Issue "To do"#1](https://github.com/brixxt27/ft_containers/issues/1)
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
- 넌 표준 라이브러리의 모든 것을 사용할 수 있어.

