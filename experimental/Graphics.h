#include <ae_std.h>
#include <ae_math.h>
#include <Object3D.h>
#include <vector>

using namespace AlphaEngine::Math;
using namespace AlphaEngine;

namespace AlphaEngine { namespace Graphics {
	
	class Buffer
	{
	public:
	
		Buffer();
		~Buffer();
		
		void setData(Vector3[] _data);
		
	private:
		Vector3[] data;
			
	};
	
	class Model
	{
	public:
		
		Model();
		~Model();
		
		void import(str path);
		
		Mesh[] getMeshes();
		int meshCount();
	
	private:
		str mdl_path;
	};
	
	class Material
	{
	public:
		
		Material();
		~Material();
	
	private:
	};
	
} } // end of namespaces
