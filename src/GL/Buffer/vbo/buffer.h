#include<gl.h>
#include<vector>
#include<GL/Texture/texture.h>
namespace GL
{
	class buffer
	{
	private:
		GLuint vao;
		GLuint vbo;
		GLuint ebo;
		std::vector<GLuint>mBuffer;
		std::vector<float>mPoints;
		std::vector<GLfloat>mIndex;
		GLsizei n;
		texture tex;
		void bind_vao();
		void bind_vbo();
		void loger();
	public:
		void render(GLenum target, int count);
		void data_buffer(std::vector<float>mPoints);
		void indexing(std::vector<GLint>mIndex);
		void import_texture();
		~buffer();
	};
}

