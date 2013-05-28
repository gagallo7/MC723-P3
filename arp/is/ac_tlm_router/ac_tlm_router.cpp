#include "ac_tlm_router.h"

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_router;

/// Constructor
ac_tlm_router::ac_tlm_router( sc_module_name module_name , int k ) :
  sc_module( module_name ),
  target_export("iport"),
  DM_port("DM_port", 5242880U)
{
    /// Binds target_export to the memory
    target_export( *this );
}
/// Destructor
ac_tlm_router::~ac_tlm_router() {
  delete [] memory;
}

