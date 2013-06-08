#ifndef AC_TLM_ROUTER_H_
#define AC_TLM_ROUTER_H_

//////////////////////////////////////////////////////////////////////////////

// Standard includes
// SystemC includes
#include <systemc>
// ArchC includes
#include "ac_tlm_protocol.H"
#include "ac_tlm_port.H"
//////////////////////////////////////////////////////////////////////////////

#define LOCK_ADDR (6 * 1024 * 1024)

// using statements
using tlm::tlm_transport_if;

//////////////////////////////////////////////////////////////////////////////

//#define DEBUG

/// Namespace to isolate memory from ArchC
namespace user
{

	/// A TLM memory
	class ac_tlm_router :
		public sc_module,
		public ac_tlm_transport_if // Using ArchC TLM protocol
	{
		public:

			//Storage devices
			ac_tlm_port DM_port;
			ac_tlm_port DL_port;

			/// Exposed port with ArchC interface
			sc_export< ac_tlm_transport_if > target_export;

			/**
			 * Implementation of TLM transport method that
			 * handle packets of the protocol doing apropriate actions.
			 * This method must be implemented (required by SystemC TLM).
			 * @param request is a received request packet
			 * @return A response packet to be send
			 */
			ac_tlm_rsp transport( const ac_tlm_req &request ) {
				switch(request.addr) {
					case LOCK_ADDR:
						return DL_port->transport(request);

					default:
						return DM_port->transport(request);
				}
			}


			/**
			 * Default constructor.
			 *
			 * @param k Memory size in kilowords.
			 *
			 */
			ac_tlm_router( sc_module_name module_name );

			/**
			 * Default destructor.
			 */
			~ac_tlm_router();


	};

};

#endif //AC_TLM_ROUTER_H_
