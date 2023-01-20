#include <pet.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_pet(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// pet_expr_type file:pet.h line:64
	pybind11::enum_<pet_expr_type>(M(""), "pet_expr_type", pybind11::arithmetic(), "")
		.value("pet_expr_error", pet_expr_error)
		.value("pet_expr_access", pet_expr_access)
		.value("pet_expr_call", pet_expr_call)
		.value("pet_expr_cast", pet_expr_cast)
		.value("pet_expr_int", pet_expr_int)
		.value("pet_expr_double", pet_expr_double)
		.value("pet_expr_op", pet_expr_op)
		.export_values();

;

	// pet_op_type file:pet.h line:74
	pybind11::enum_<pet_op_type>(M(""), "pet_op_type", pybind11::arithmetic(), "")
		.value("pet_op_add_assign", pet_op_add_assign)
		.value("pet_op_sub_assign", pet_op_sub_assign)
		.value("pet_op_mul_assign", pet_op_mul_assign)
		.value("pet_op_div_assign", pet_op_div_assign)
		.value("pet_op_and_assign", pet_op_and_assign)
		.value("pet_op_xor_assign", pet_op_xor_assign)
		.value("pet_op_or_assign", pet_op_or_assign)
		.value("pet_op_assign", pet_op_assign)
		.value("pet_op_add", pet_op_add)
		.value("pet_op_sub", pet_op_sub)
		.value("pet_op_mul", pet_op_mul)
		.value("pet_op_div", pet_op_div)
		.value("pet_op_mod", pet_op_mod)
		.value("pet_op_shl", pet_op_shl)
		.value("pet_op_shr", pet_op_shr)
		.value("pet_op_eq", pet_op_eq)
		.value("pet_op_ne", pet_op_ne)
		.value("pet_op_le", pet_op_le)
		.value("pet_op_ge", pet_op_ge)
		.value("pet_op_lt", pet_op_lt)
		.value("pet_op_gt", pet_op_gt)
		.value("pet_op_minus", pet_op_minus)
		.value("pet_op_post_inc", pet_op_post_inc)
		.value("pet_op_post_dec", pet_op_post_dec)
		.value("pet_op_pre_inc", pet_op_pre_inc)
		.value("pet_op_pre_dec", pet_op_pre_dec)
		.value("pet_op_address_of", pet_op_address_of)
		.value("pet_op_assume", pet_op_assume)
		.value("pet_op_kill", pet_op_kill)
		.value("pet_op_and", pet_op_and)
		.value("pet_op_xor", pet_op_xor)
		.value("pet_op_or", pet_op_or)
		.value("pet_op_not", pet_op_not)
		.value("pet_op_land", pet_op_land)
		.value("pet_op_lor", pet_op_lor)
		.value("pet_op_lnot", pet_op_lnot)
		.value("pet_op_cond", pet_op_cond)
		.value("pet_op_last", pet_op_last)
		.export_values();

;

	// pet_un_arg_type file:pet.h line:118
	pybind11::enum_<pet_un_arg_type>(M(""), "pet_un_arg_type", pybind11::arithmetic(), "")
		.value("pet_un_arg", pet_un_arg)
		.export_values();

;

	// pet_bin_arg_type file:pet.h line:125
	pybind11::enum_<pet_bin_arg_type>(M(""), "pet_bin_arg_type", pybind11::arithmetic(), "")
		.value("pet_bin_lhs", pet_bin_lhs)
		.value("pet_bin_rhs", pet_bin_rhs)
		.export_values();

;

	// pet_ter_arg_type file:pet.h line:133
	pybind11::enum_<pet_ter_arg_type>(M(""), "pet_ter_arg_type", pybind11::arithmetic(), "")
		.value("pet_ter_cond", pet_ter_cond)
		.value("pet_ter_true", pet_ter_true)
		.value("pet_ter_false", pet_ter_false)
		.export_values();

;

	// pet_tree_type file:pet.h line:277
	pybind11::enum_<pet_tree_type>(M(""), "pet_tree_type", pybind11::arithmetic(), "")
		.value("pet_tree_error", pet_tree_error)
		.value("pet_tree_expr", pet_tree_expr)
		.value("pet_tree_block", pet_tree_block)
		.value("pet_tree_break", pet_tree_break)
		.value("pet_tree_continue", pet_tree_continue)
		.value("pet_tree_decl", pet_tree_decl)
		.value("pet_tree_decl_init", pet_tree_decl_init)
		.value("pet_tree_if", pet_tree_if)
		.value("pet_tree_if_else", pet_tree_if_else)
		.value("pet_tree_for", pet_tree_for)
		.value("pet_tree_infinite_loop", pet_tree_infinite_loop)
		.value("pet_tree_while", pet_tree_while)
		.value("pet_tree_return", pet_tree_return)
		.export_values();

;

	{ // pet_stmt file:pet.h line:376
		pybind11::class_<pet_stmt, std::shared_ptr<pet_stmt>> cl(M(""), "pet_stmt", "");
		cl.def( pybind11::init( [](){ return new pet_stmt(); } ) );
		cl.def_readwrite("n_arg", &pet_stmt::n_arg);
	}
	// pet_stmt_is_assign(struct pet_stmt *) file:pet.h line:389
	M("").def("pet_stmt_is_assign", (int (*)(struct pet_stmt *)) &pet_stmt_is_assign, "C++: pet_stmt_is_assign(struct pet_stmt *) --> int", pybind11::arg("stmt"));

	// pet_stmt_is_kill(struct pet_stmt *) file:pet.h line:391
	M("").def("pet_stmt_is_kill", (int (*)(struct pet_stmt *)) &pet_stmt_is_kill, "C++: pet_stmt_is_kill(struct pet_stmt *) --> int", pybind11::arg("stmt"));

	// pet_stmt_can_build_ast_exprs(struct pet_stmt *) file:pet.h line:398
	M("").def("pet_stmt_can_build_ast_exprs", (int (*)(struct pet_stmt *)) &pet_stmt_can_build_ast_exprs, "C++: pet_stmt_can_build_ast_exprs(struct pet_stmt *) --> int", pybind11::arg("stmt"));

	{ // pet_type file:pet.h line:426
		pybind11::class_<pet_type, std::shared_ptr<pet_type>> cl(M(""), "pet_type", "");
		cl.def( pybind11::init( [](){ return new pet_type(); } ) );
	}
	{ // pet_array file:pet.h line:454
		pybind11::class_<pet_array, std::shared_ptr<pet_array>> cl(M(""), "pet_array", "");
		cl.def( pybind11::init( [](){ return new pet_array(); } ) );
		cl.def_readwrite("element_is_record", &pet_array::element_is_record);
		cl.def_readwrite("element_size", &pet_array::element_size);
		cl.def_readwrite("live_out", &pet_array::live_out);
		cl.def_readwrite("uniquely_defined", &pet_array::uniquely_defined);
		cl.def_readwrite("declared", &pet_array::declared);
		cl.def_readwrite("exposed", &pet_array::exposed);
		cl.def_readwrite("outer", &pet_array::outer);
	}
	{ // pet_implication file:pet.h line:474
		pybind11::class_<pet_implication, std::shared_ptr<pet_implication>> cl(M(""), "pet_implication", "");
		cl.def( pybind11::init( [](){ return new pet_implication(); } ) );
		cl.def_readwrite("satisfied", &pet_implication::satisfied);
	}
	{ // pet_independence file:pet.h line:488
		pybind11::class_<pet_independence, std::shared_ptr<pet_independence>> cl(M(""), "pet_independence", "");
		cl.def( pybind11::init( [](){ return new pet_independence(); } ) );
	}
	{ // pet_scop file:pet.h line:513
		pybind11::class_<pet_scop, std::shared_ptr<pet_scop>> cl(M(""), "pet_scop", "");
		cl.def( pybind11::init( [](){ return new pet_scop(); } ) );
		cl.def_readwrite("n_type", &pet_scop::n_type);
		cl.def_readwrite("n_array", &pet_scop::n_array);
		cl.def_readwrite("n_stmt", &pet_scop::n_stmt);
		cl.def_readwrite("n_implication", &pet_scop::n_implication);
		cl.def_readwrite("n_independence", &pet_scop::n_independence);
	}
	// pet_op_str(enum pet_op_type) file:pet.h line:538
	M("").def("pet_op_str", (const char * (*)(enum pet_op_type)) &pet_op_str, "C++: pet_op_str(enum pet_op_type) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("op"));

	// pet_op_is_inc_dec(enum pet_op_type) file:pet.h line:539
	M("").def("pet_op_is_inc_dec", (int (*)(enum pet_op_type)) &pet_op_is_inc_dec, "C++: pet_op_is_inc_dec(enum pet_op_type) --> int", pybind11::arg("op"));

	// pet_scop_align_params(struct pet_scop *) file:pet.h line:564
	M("").def("pet_scop_align_params", (struct pet_scop * (*)(struct pet_scop *)) &pet_scop_align_params, "C++: pet_scop_align_params(struct pet_scop *) --> struct pet_scop *", pybind11::return_value_policy::automatic, pybind11::arg("scop"));

	// pet_scop_has_data_dependent_accesses(struct pet_scop *) file:pet.h line:567
	M("").def("pet_scop_has_data_dependent_accesses", (int (*)(struct pet_scop *)) &pet_scop_has_data_dependent_accesses, "C++: pet_scop_has_data_dependent_accesses(struct pet_scop *) --> int", pybind11::arg("scop"));

	// pet_scop_has_data_dependent_conditions(struct pet_scop *) file:pet.h line:569
	M("").def("pet_scop_has_data_dependent_conditions", (int (*)(struct pet_scop *)) &pet_scop_has_data_dependent_conditions, "C++: pet_scop_has_data_dependent_conditions(struct pet_scop *) --> int", pybind11::arg("scop"));

	// pet_scop_can_build_ast_exprs(struct pet_scop *) file:pet.h line:575
	M("").def("pet_scop_can_build_ast_exprs", (int (*)(struct pet_scop *)) &pet_scop_can_build_ast_exprs, "C++: pet_scop_can_build_ast_exprs(struct pet_scop *) --> int", pybind11::arg("scop"));

	// pet_scop_dump(struct pet_scop *) file:pet.h line:577
	M("").def("pet_scop_dump", (void (*)(struct pet_scop *)) &pet_scop_dump, "C++: pet_scop_dump(struct pet_scop *) --> void", pybind11::arg("scop"));

	// pet_scop_free(struct pet_scop *) file:pet.h line:578
	M("").def("pet_scop_free", (struct pet_scop * (*)(struct pet_scop *)) &pet_scop_free, "C++: pet_scop_free(struct pet_scop *) --> struct pet_scop *", pybind11::return_value_policy::automatic, pybind11::arg("scop"));

}
