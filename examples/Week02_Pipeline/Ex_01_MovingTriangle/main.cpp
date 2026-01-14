#include <sb7.h>

class moving_triangle : public sb7::application
{
public:
	GLuint compile_shader() {

		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* vertex_shader_source[] = 
		{
			"#version 430 core\n"
			"layout (location = 0) in vec4 offset;\n"
			"void main() \n"
			"{\n"
			"const vec4 vertices[3] = vec4[3](\n"
			"vec4(0.0, 0.5, 0.0, 1.0),\n"
			"vec4(-0.5, -0.5, 0.0, 1.0),\n"
			"vec4(0.5, -0.5, 0.0, 1.0)\n"
			");\n"
			"gl_Position = vertices[gl_VertexID] + offset; \n"
			"}\n"
		};

		const GLchar* fragment_shader_source[] = 
		{
			"#version 430 core\n"
			"out vec4 color;\n"
			"void main() \n"
			"{\n"
			"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n"
		};

		glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
		glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);

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
		rendering_program = compile_shader();

		glGenVertexArrays(1, &vertex_array_object);
		glBindVertexArray(vertex_array_object);
	}

	virtual void shutdown()
	{
		glDeleteVertexArrays(1, &vertex_array_object);
		glDeleteProgram(rendering_program);
	}

	virtual void render(double currentTime)
	{
		const GLfloat backgroundColor[] = { 0.2f, 0.3f, 0.3f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, backgroundColor);
		
		glUseProgram(rendering_program);

		// glVertexAttrib4fv(): 지정한 Attribute Location에 Vertex Attribute 설정하기
		GLfloat attrib[4] = {(float)sin(currentTime) * 0.5f, (float)cos(currentTime) * 0.5f, 0.0f, 1.0f};
		glVertexAttrib4fv(0, attrib);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

private:
	GLuint rendering_program;
	GLuint vertex_array_object;
};

DECLARE_MAIN(moving_triangle);