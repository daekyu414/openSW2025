<div align="center">

# OpenSW 2025

**리눅스 환경에서 익히는 오픈소스 소프트웨어 실습 기록**

`C` · `Linux` · `Bash` · `Python` · `Git` · `Make`

</div>

---

## 📚 실습 둘러보기

| 실습 | 주제 | 주요 내용 |
| :--- | :--- | :--- |
| [Lab 0](lab0/) | 파일과 디렉터리 | 파일 복사, 출력 리다이렉션, 심볼릭 링크 |
| [Lab 0 copied](lab0_copied/) | 파일 복사 연습 | Lab 0 파일을 복사한 결과 |
| [Lab 1](lab1/) · [Lab 3](lab3/) | 실습 자리 | 현재는 빈 디렉터리 |
| [Lab 2](lab2/) | Python | 환경 변수 읽기 |
| [Lab 4](lab4_bash/) | Bash | 셸 스크립트와 함수 |
| [Lab 5](lab5_gcc/) | GCC | C 소스, 헤더, 정적·공유 라이브러리 |
| [Lab 6](lab6_make/) | Make | Makefile을 이용한 빌드 |
| [Lab 7](lab7_git/) | Git | 버전 관리와 C 프로젝트 |
| [Lab 8](lab8_syscall/) | 시스템 호출 | 파일 열기·복사와 프로세스 ID |
| [Lab 9](lab9_process/) | 프로세스 | `fork`, `exec`, `wait` 실습 |
| [Lab 10](lab10_signal/) | 시그널 | 시그널 처리와 알람 |
| [Lab 11](lab11_myshell/) | 미니 셸 | 입력 파싱, 내장 명령, 프로세스 실행 |

## 📝 과제 저장소

[`OpenSW_Assignment/`](OpenSW_Assignment/)에는 주차별 과제를 모았습니다. 별도 [OpenSW_Assignment 저장소](https://github.com/daekyu414/OpenSW_Assignment)를 **Git 서브모듈**로 연결했으므로 과제 저장소의 커밋 기록은 독립적으로 유지됩니다.

새로 복제할 때는 서브모듈을 함께 받으세요.

```bash
git clone --recurse-submodules https://github.com/daekyu414/openSW2025.git
```

이미 복제했다면 저장소 루트에서 `git submodule update --init --recursive`를 실행하면 됩니다.

## 🚀 빠르게 실행하기

GCC와 Make가 설치된 리눅스 환경에서 Lab 7 예제를 빌드할 수 있습니다.

```bash
mkdir -p lab7_git/bin lab7_git/obj
make -C lab7_git
./lab7_git/bin/myapp
```

Lab 11 미니 셸도 같은 방식으로 빌드할 수 있습니다.

```bash
mkdir -p lab11_myshell/bin lab11_myshell/obj
make -C lab11_myshell
./lab11_myshell/bin/myshell
```

미니 셸을 종료할 때는 `quit`을 입력하세요. 각 실습의 코드는 학습 과정의 결과물이므로 실행 전에 소스와 Makefile을 확인해 주세요.

## 🗂️ 함께 보관한 자료

- [`linux-6.17.6/`](linux-6.17.6/): 리눅스 커널 소스 트리
- [`linux-6.17.6.tar.xz`](linux-6.17.6.tar.xz): 커널 소스 압축 파일. 100MB를 넘으므로 Git LFS로 관리합니다.

압축 파일의 실제 내용을 받으려면 [Git LFS](https://git-lfs.com/)를 설치한 뒤 `git lfs pull`을 실행하세요. 빌드 결과물과 실행 바이너리는 루트 및 각 실습 폴더의 `.gitignore` 규칙에 따라 저장소에서 제외됩니다.
