#include <ae_std.h>
#include <ae_math.h>
#include <Object3D.h>
#include <vector>

using namespace AlphaEngine::Math;
using namespace AlphaEngine;

namespace AlphaEngine { namespace Graphics {
	
	// Scene - place where rendering objects
	class Scene
	{
	public:
		
		Scene();
		~Scene();
		
		void addCamera(Camera* cam);
		void addObject(Object3D* obj);
		
		void draw();
	
	private:
		vector<Object3D*> objects;	
	};
	
} } // end of namespaces
