/******************************************************
 * This is the main file for the mips1 ArchC model    *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/

// Rodolfo editou aqui
//
const char *project_name="mips1";
const char *project_file="mips1.ac";
const char *archc_version="2.0beta1";
const char *archc_options="-abi -dy ";

#include  <systemc.h>
#include  "mips1.H"
#include  "ac_tlm_mem.h"
#include  "ac_tlm_router.h"
#include  "ac_tlm_locker.h"

using user::ac_tlm_mem;
using user::ac_tlm_router;
using user::ac_tlm_locker;

int sc_main(int ac, char *av[])
{

	char **argv = (char **) malloc( ac * sizeof(char *) + 1);
	for ( int i = 0; i < ac; i++)
		argv[i] = (char *) malloc( strlen(av[i]) * sizeof(char) + 1);	

	//!  ISA simulator
	mips1 mips1_proc1("mips1");
	mips1 mips1_proc2("mips2");
	mips1 mips1_proc3("mips3");
	mips1 mips1_proc4("mips4");
	mips1 mips1_proc5("mips5");
	mips1 mips1_proc6("mips6");
	mips1 mips1_proc7("mips7");
	mips1 mips1_proc8("mips8");

	ac_tlm_mem mem("mem");
	ac_tlm_router router("router");
	ac_tlm_locker locker("locker");

#ifdef AC_DEBUG
	ac_trace("mips1_proc1.trace");
#endif 

	router.DL_port(locker.target_export);
	router.DM_port(mem.target_export);
	mips1_proc1.DM_port(router.target_export);
	mips1_proc2.DM_port(router.target_export);
	mips1_proc3.DM_port(router.target_export);
	mips1_proc4.DM_port(router.target_export);
	mips1_proc5.DM_port(router.target_export);
	mips1_proc6.DM_port(router.target_export);
	mips1_proc7.DM_port(router.target_export);
	mips1_proc8.DM_port(router.target_export);

	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc1.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc2.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc3.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc4.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc5.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc6.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc7.init(ac, argv);
	for (int i = 0; i < ac; i++ ) strcpy(argv[i],av[i]);
	mips1_proc8.init(ac, argv);
	cerr << endl;

	sc_start();

	mips1_proc1.PrintStat();
	mips1_proc2.PrintStat();
	mips1_proc3.PrintStat();
	mips1_proc4.PrintStat();
	mips1_proc5.PrintStat();
	mips1_proc6.PrintStat();
	mips1_proc7.PrintStat();
	mips1_proc8.PrintStat();
	cerr << endl;

#ifdef AC_STATS
	mips1_proc1.ac_sim_stats.time = sc_simulation_time();
	mips1_proc1.ac_sim_stats.print();
#endif 

#ifdef AC_DEBUG
	ac_close_trace();
#endif 

	return mips1_proc1.ac_exit_status;
}
