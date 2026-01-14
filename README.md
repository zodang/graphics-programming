# Graphics Programming
<img src="https://www.khronos.org/assets/images/api_logos/opengl.svg" width="400px" alt="OpenGL">

</br>

## 📌 Project Overview

이 프로젝트는 Modern OpenGL 환경에서 그래픽스 파이프라인의 동작 원리를 학습하기 위한 OpenGL 예제 모음입니다.

각 예제는 OpenGL SuperBible 7에서 다루는 개념을 참고하여 정리되었습니다.

</br>

## 📂 Project Structure
```
graphics-programming/
 ├─ GraphicsProgramming.sln
 ├─ examples/
 │   ├─ Week01_Basics/
 │   │   └─ Ex_00_DrawPinwheel/
 │   ├─ Week02_Pipeline/
 │   │   └─ Ex_01_MovingTriangle/
 │   └─ ...
 └─ README.md
```

</br>

## 🚀 How to Build & Run
**1. 솔루션 열기**

Visual Studio에서 최상위 솔루션 파일을 선택합니다.
   ```
   GraphicsProgramming.sln
   ```
**2. 프로젝트 위치 확인**

Solution Explorer에서 실행할 예제 프로젝트를 선택합니다.

**3. 시작 프로젝트 설정**

Solution Explorer에서 선택한 예제 프로젝트를 우클릭 후, **Set as Startup Project**를 선택합니다.

**4. 실행**

F5 혹은 ctrl+F5로 OpenGL 프로젝트를 실행합니다.

</br>

## 📘 Example Projects
| Week | Project | Description |
|-----:|---------|-------------|
| Week01 | [Ex_00_DrawPinwheel](examples/Week01_Basics/Ex_00_DrawPinwheel) | gl_VertexID를 사용하여 별도의 버텍스 버퍼 없이 여러 개의 삼각형을 렌더링하는 예제 |
|        | [Ex_01_DrawPoint](examples/Week01_Basics/Ex_01_DrawPointl) | OpenGL 렌더링의 최소 구성 요소와 단일 점을 렌더링 하는 예제 |
|        | [Ex_02_DrawTriangle](examples/Week01_Basics/Ex_02_DrawTriangle) | glDrawArrays로 삼각형을 렌더링하고, 시간 값에 따라 배경색을 변화시키는 예제 |
| Week02 | [Ex_01_MovingTriangle](examples/Week02_Pipeline/Ex_01_MovingTriangle) | Vertex Attribute를 통해 값을 셰이더로 전달하여 이동하는 삼각형을 렌더링하는 예제 |
