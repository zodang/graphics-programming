#include <sb7.h>

class draw_pinwheel : public sb7::application
{
public:
	GLuint CompileShader()
	{
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* vertex_source[] = 
		{
			"#version 430 core \n"
			"void main() { \n"
			"const vec4 vertices[12] = vec4[12](\n"
			"vec4(0.00f, 0.00f, 0.0f, 1.00f),\n"
			"vec4(0.00f, 0.25f, 0.00f, 1.00f),\n"
			"vec4(-0.25f, 0.25f, 0.00f, 1.00f),\n"
			"vec4(0.00f, 0.00f, 0.00f, 1.00f),\n"
			"vec4(-0.25f, 0.00f, 0.00f, 1.00f),\n"
			"vec4(-0.25f, -0.25f, 0.00f, 1.00f),\n"
			"vec4(0.00f, 0.00f, 0.00f, 1.00f),\n"
			"vec4(0.00f, -0.25f, 0.00f, 1.00f),\n"
			"vec4(0.25f, -0.25f, 0.00f, 1.00f),\n"
			"vec4(0.00f, 0.00f, 0.00f, 1.00f),\n"
			"vec4(0.25f, 0.00f, 0.00f, 1.00f),\n"
			"vec4(0.25f, 0.25f, 0.00f, 1.00f)\n"
			"); \n"
			"gl_Position = vertices[gl_VertexID];\n"
			"}\n"
		};

		const GLchar* fragment_source[] =
		{ 
			"#version 430 core \n"
			"out vec4 color; \n"
			"void main() { \n"
			"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n"
		};

		glShaderSource(vertex_shader, 1, vertex_source, NULL);
		glShaderSource(fragment_shader, 1, fragment_source, NULL);

		glCompileShader(vertex_shader);
		glCompileShader(fragment_shader);

		GLuint program = glCreateProgram();

		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);

		glLinkProgram(program);

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		return program;
	}

	virtual void startup()
	{
		program = CompileShader();
		glGenVertexArrays(1, &vertex_array_object);
		glBindVertexArray(vertex_array_object);
	}

	virtual void shutdown()
	{
		glDeleteProgram(program);
		glDeleteVertexArrays(1, &vertex_array_object);
	}
	
	virtual void render(double currentTime)
	{
		const GLfloat background[] = { 0.2f, 0.3f, 0.3f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, background);

		glUseProgram(program);
		glDrawArrays(GL_TRIANGLES, 0, 12);
	}

private:
	GLuint program;
	GLuint vertex_array_object;
};

DECLARE_MAIN(draw_pinwheel);