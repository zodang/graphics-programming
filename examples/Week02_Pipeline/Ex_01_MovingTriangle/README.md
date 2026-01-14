# Ex_01_MovingTriangle
render() 함수의 currentTime 값에 따라 이동하는 삼각형을 렌더링하는 예제이다.
<br/>

<img src="Ex_01_MovingTriangle.gif" width="400">

### Implementation Notes
- render() 함수에서 vertex shader로 넘길 attrib 값을 설정한다.
- glVertexAttrib4fv(0, attrib)를 통해 Attribute Loaction 0번에 Vertex Attribute 값을 설정한.
- vertex shader에서 gl_Position에 전달받은 offset 값을 더해 정점 위치를 이동시킨다.

### Key Learning Points
- glVertexAttrib4fv()를 사용하면 상수 값을 셰이더로 넘길 수 있다.
- layout(location = N)을 사용하여 Attribute Location을 명시적으로 지정할 수 있다.
