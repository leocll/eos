/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once
#include <fc/exception/exception.hpp>

#define RESULT_JSON(key,value) fc::mutable_variant_object(key,value)
#define PRINT_OUT_RESULT_JSON(v) FC_MULTILINE_MACRO_BEGIN \
    print_out_result_json(fc::variant(v)); \
FC_MULTILINE_MACRO_END

namespace eosio {
    namespace client {
        namespace print_out {
            class out_result_object {

            public:
                out_result_object();

                void add_warning(std::string warning);

                void set_transaction(std::string transaction_id, std::string net, std::string cpu);

                void add_action_tree(fc::mutable_variant_object action_tree);

                out_result_object& set_info( std::string key, fc::variant var );

                void print();

            private:
                std::string _warning = "";
                fc::mutable_variant_object _transaction_obj = fc::mutable_variant_object();
                std::vector<fc::mutable_variant_object> _action_tree_obj;
                fc::mutable_variant_object _info_obj = fc::mutable_variant_object();
            };

            void print_out_result_json(const fc::variant &v);

            void print_parse_error_json(std::string description, int64_t code = 100, std::string advice = "",
                                        std::string explanation = "", std::string stack_trace = "");
        }
    }
}

namespace eosio { namespace client { namespace help {
    bool print_recognized_errors(const fc::exception& e, const bool verbose_errors);
    bool print_help_text(const fc::exception& e);
}}}