#include <ae_std.h>
#include <ae_math.h>
#include <Graphics.h>
#include <vector>

using namespace AlphaEngine::Math;
using namespace AlphaEngine;

namespace AlphaEngine { namespace Graphics {
	
	class Object3D
	{
	public:
		
		Object3D();
		~Object3D();
		
		void addChild(Object3D* child);
		void removeChild(Object3D* child);
		void setParent(Object3D* _parent);
		
	
	private:
		std::vector<Object3D*> children;
		Object3D* parent;	
	};
	
	class Camera : Object3D
	{
	public:
		
		Camera();
		~Camera();
		
	private:
	};
	
	class Light : Object3D
	{
	public:
		Light();
		~Light();
		
	private:
	};
	
	class Mesh : Object3D
	{
	public:
		
		Mesh();
		~Mesh();
		
	private:
		Buffer vertices, indices;	
	};
	
	class Cube : Mesh
	{
	public:
		
		Cube();
		~Cube();
		
	private:
		str texture_path;
	};
	
	class ModelObject : Object3D
	{
	public:
		
		ModelObject();
		~ModelObject();
		
	private:
		Model* mdl;
	};
	
	class Displacement : Mesh
	{
	public:
		
		Displacement();
		~Displacement();
		
	private:
	};
	
} } // end of namespaces
