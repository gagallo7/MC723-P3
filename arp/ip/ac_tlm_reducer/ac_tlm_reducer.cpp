//////////////////////////////////////////////////////////////////////////////
// Standard includes
// SystemC includes
// ArchC includes

#include "ac_tlm_reducer.h"
#define CHANGE_ENDIAN(value) (0x00000000 | (value << 24) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x0000FF00) | (value >> 24))

//////////////////////////////////////////////////////////////////////////////

/// Namespace to isolate memory from ArchC
using user::ac_tlm_reducer;

/// Constructor
ac_tlm_reducer::ac_tlm_reducer( sc_module_name module_name , int k ) :
  sc_module( module_name ),
  target_export("iport")
{
    /// Binds target_export to the memory
    target_export( *this );

}

/// Destructor
ac_tlm_reducer::~ac_tlm_reducer() {

}

/** Internal Write
  * Note: Always write 32 bits
  * @param a is the address to write
  * @param d id the data being write
  * @returns A TLM response packet with SUCCESS
*/
ac_tlm_rsp_status ac_tlm_reducer::writem( const uint32_t &a , const uint32_t &d )
{
  sum += CHANGE_ENDIAN(*((uint32_t *) &d));
  return SUCCESS;
}

/** Internal Read
  * Note: Always read 32 bits
  * @param a is the address to read
  * @param d id the data that will be read
  * @returns A TLM response packet with SUCCESS and a modified d
*/
ac_tlm_rsp_status ac_tlm_reducer::readm( const uint32_t &a , uint32_t &d )
{
  *((uint32_t *) &d) = CHANGE_ENDIAN(sum);

  return SUCCESS;
}



