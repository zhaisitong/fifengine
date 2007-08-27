%module pather
%{
#include "pathfinder/linearpather/linearpather.h"
%}

%include "model/metamodel/abstractpather.h"

namespace FIFE { namespace model {
	class LinearPather: public AbstractPather {
	public:
		LinearPather();
		virtual ~LinearPather();
		virtual void setMap(Map* map); 
		virtual int getNextCells(const Location& curpos, const Location& target,  
		                         std::vector<Location>& nextnodes, const int session_id=-1);
	};
}}
