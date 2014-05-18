/* This file is automatically generated
   do not edit this file directly! */

#include "memory-leak-1.h"
void place_user_fn_105(ca::Context &ctx, ca::TokenList<int > &place);
class Tokens_111  : public ca::Binding {
	public:
	Tokens_111() {};
	Tokens_111(const Tokens_111 &t) {
		blocked = t.blocked;
		root = t.root;
		if (t.token_collective != NULL) {
			token_collective = new ca::Token<int >(t.token_collective->value);
		} else {
			token_collective = NULL;
		}
		if (t.token_1007 != NULL) {
			token_1007 = new ca::Token<int >(t.token_1007->value);
		} else {
			token_1007 = NULL;
		}
		if (t.token_1009 != NULL) {
			token_1009 = new ca::Token<std::vector<int> >(t.token_1009->value);
		} else {
			token_1009 = NULL;
		}
	}
	Tokens_111& operator=(const Tokens_111 &t) {
		if (this != &t) {
			blocked = t.blocked;
			root = t.root;
			if (t.token_collective != NULL) {
				delete token_collective;
				token_collective = new ca::Token<int >(t.token_collective->value);
			} else {
				token_collective = NULL;
			}
			if (t.token_1007 != NULL) {
				delete token_1007;
				token_1007 = new ca::Token<int >(t.token_1007->value);
			} else {
				token_1007 = NULL;
			}
			if (t.token_1009 != NULL) {
				delete token_1009;
				token_1009 = new ca::Token<std::vector<int> >(t.token_1009->value);
			} else {
				token_1009 = NULL;
			}
		}
		return *this;
	}
	~Tokens_111() {
		if (token_collective != NULL) {
			delete token_collective;
		}
		if (token_1007 != NULL) {
			delete token_1007;
		}
		if (token_1009 != NULL) {
			delete token_1009;
		}
	}
	ca::Binding* copy() {
		Tokens_111 *t = new Tokens_111(*this);
		return t;
	}
	bool blocked;
	int root;
	ca::Token<int > *token_collective;
	ca::Token<int > *token_1007;
	ca::Token<std::vector<int> > *token_1009;
};
class Transition_111  : public ca::TransitionDef {
	public:
	Transition_111() : ca::TransitionDef(111, "", ca::TRANSITION_COLLECTIVE, 10) {
	}
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	ca::Binding* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, ca::Binding *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
	bool is_blocked(ca::Binding *data);
};
static Transition_111 transition_111;

class Vars_102 {
	public:
	Vars_102(ca::Context &ctx,ca::TokenList<int > &data,std::vector<int> &list) : ctx(ctx),data(data),list(list) {
	}
	ca::Context &ctx;
	ca::TokenList<int > &data;
	std::vector<int> &list;
};
void transition_user_fn_102(ca::Context &ctx, Vars_102 &var);
class Tokens_102  : public ca::Binding {
	public:
	Tokens_102() {};
	Tokens_102(const Tokens_102 &t) {
		tokens_1002 = t.tokens_1002;
	}
	Tokens_102& operator=(const Tokens_102 &t) {
		if (this != &t) {
			tokens_1002 = t.tokens_1002;
		}
		return *this;
	}
	~Tokens_102() {
	}
	ca::Binding* copy() {
		Tokens_102 *t = new Tokens_102(*this);
		return t;
	}
	ca::Place<int > tokens_1002;
};
class Transition_102  : public ca::TransitionDef {
	public:
	Transition_102() : ca::TransitionDef(102, "", ca::TRANSITION_NORMAL, 0) {
	}
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	ca::Binding* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, ca::Binding *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_102 transition_102;

class Tokens_123  : public ca::Binding {
	public:
	Tokens_123() {};
	Tokens_123(const Tokens_123 &t) {
		if (t.token_1013 != NULL) {
			token_1013 = new ca::Token<int >(t.token_1013->value);
		} else {
			token_1013 = NULL;
		}
	}
	Tokens_123& operator=(const Tokens_123 &t) {
		if (this != &t) {
			if (t.token_1013 != NULL) {
				delete token_1013;
				token_1013 = new ca::Token<int >(t.token_1013->value);
			} else {
				token_1013 = NULL;
			}
		}
		return *this;
	}
	~Tokens_123() {
		if (token_1013 != NULL) {
			delete token_1013;
		}
	}
	ca::Binding* copy() {
		Tokens_123 *t = new Tokens_123(*this);
		return t;
	}
	ca::Token<int > *token_1013;
};
class Transition_123  : public ca::TransitionDef {
	public:
	Transition_123() : ca::TransitionDef(123, "send", ca::TRANSITION_IMMEDIATE, 0) {
	}
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	ca::Binding* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, ca::Binding *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_123 transition_123;

class Vars_130 {
	public:
	Vars_130(ca::Context &ctx,ca::TokenList<int > &data) : ctx(ctx),data(data) {
	}
	ca::Context &ctx;
	ca::TokenList<int > &data;
};
void transition_user_fn_130(ca::Context &ctx, Vars_130 &var);
class Tokens_130  : public ca::Binding {
	public:
	Tokens_130() {};
	Tokens_130(const Tokens_130 &t) {
		tokens_1018 = t.tokens_1018;
	}
	Tokens_130& operator=(const Tokens_130 &t) {
		if (this != &t) {
			tokens_1018 = t.tokens_1018;
		}
		return *this;
	}
	~Tokens_130() {
	}
	ca::Binding* copy() {
		Tokens_130 *t = new Tokens_130(*this);
		return t;
	}
	ca::Place<int > tokens_1018;
};
class Transition_130  : public ca::TransitionDef {
	public:
	Transition_130() : ca::TransitionDef(130, "quit", ca::TRANSITION_NORMAL, 0) {
	}
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	ca::Binding* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, ca::Binding *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_130 transition_130;

class Net_101  : public ca::Net {
	public:
	Net_101(ca::NetDef * def,ca::Thread * thread) : ca::Net(def, thread) {
	}
	ca::NetBase * copy() {
		Net_101 *net = new Net_101(*this);
		return net;
	}
	ca::Place<int > place_105;
	ca::Place<std::vector<int> > place_103;
	ca::Place<int > place_109;
	ca::Place<int > place_114;
	ca::Place<int > place_128;
	void write_reports_content(ca::ThreadBase *thread, ca::Output &output) {
		output.child("place");
		output.set("id", 105);
		{
			ca::Token<int > *t = place_105.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_105.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 103);
		{
			ca::Token<std::vector<int> > *t = place_103.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_103.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 109);
		{
			ca::Token<int > *t = place_109.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_109.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 114);
		{
			ca::Token<int > *t = place_114.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_114.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 128);
		{
			ca::Token<int > *t = place_128.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_128.begin());
			}
		}
		output.back();
	}
	void receive(ca::ThreadBase *__kaira__thread, int from_process, int place_pos, ca::Unpacker &unpacker) {
		switch(place_pos) {
		case 110:
		{
			ca::Token<int > *token = new ca::Token<int >();
			ca::unpack(unpacker, token->value);
			this->place_109.add_token(token);
			this->activate_transition_by_pos_id(0);
		}
		break;
		case 129:
		{
			ca::Token<int > *token = new ca::Token<int >();
			ca::unpack(unpacker, token->value);
			this->place_128.add_token(token);
			this->activate_transition_by_pos_id(3);
		}
		break;
		}
	}
};
ca::NetBase * spawn_101(ca::ThreadBase *__kaira__thread, ca::NetDef *__kaira__def) {
	Net_101 *__kaira__net = new Net_101(__kaira__def, (ca::Thread*) __kaira__thread);
	ca::Context ctx(__kaira__thread, __kaira__net);
	int __kaira__pid = __kaira__thread->get_process_id();
	if (__kaira__pid == 0) {
		{
			ca::TokenList<int > __kaira__list;
			place_user_fn_105(ctx, __kaira__list);
			__kaira__net->place_105.overtake(__kaira__list);
		}
	}
	return __kaira__net;
}
ca::FireResult Transition_111::full_fire(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	// Inscription id=113 uid=1007 expr=lock
	ca::Token < int > *__kaira__token_1007;
	bool __kaira__inscription_if_1007;
	if (!(ctx.process_id() != 0)) {
		__kaira__inscription_if_1007 = false;
		__kaira__token_1007 = new ca::Token<int >;
		__kaira__token_1007->next = __kaira__token_1007;
		__kaira__token_1007->prev = __kaira__token_1007;
	} else {
		__kaira__inscription_if_1007 = true;
		__kaira__token_1007 = __kaira__n->place_109.begin();
		if (__kaira__token_1007 == NULL) return ca::NOT_ENABLED;
		int &lock = __kaira__token_1007->value;
	}
	int &lock = __kaira__token_1007->value;
	// Inscription id=113 uid=1009 expr=list
	ca::Token < std::vector<int> > *__kaira__token_1009;
	int __kaira__root = 0;
	bool __kaira__inscription_if_1009;
	if (__kaira__root != __kaira__thread->get_process_id()) {
		__kaira__inscription_if_1009 = false;
		__kaira__token_1009 = new ca::Token<std::vector<int> >;
		__kaira__token_1009->next = __kaira__token_1009;
		__kaira__token_1009->prev = __kaira__token_1009;
	} else {
		__kaira__inscription_if_1009 = true;
		__kaira__token_1009 = __kaira__n->place_103.begin();
		if (__kaira__token_1009 == NULL) {
            delete __kaira__token_1007;                                         # TODO: tady je treba smazat tokeny
            return ca::NOT_ENABLED;
        }
		std::vector<int> &list = __kaira__token_1009->value;
	}
	std::vector<int> &list = __kaira__token_1009->value;
	{
		{
			if (__kaira__inscription_if_1007) {
				__kaira__n->place_109.remove(__kaira__token_1007);
			}
			if (__kaira__inscription_if_1009) {
				__kaira__n->place_103.remove(__kaira__token_1009);
			}
		}
		__kaira__n->activate_transition_by_pos_id(0);
		if (__kaira__root == __kaira__thread->get_process_id()) {
			const std::vector<int > &__kaira__value = list;
			int __kaira__process_count = __kaira__thread->get_process_count();
			if (__kaira__value.size() != __kaira__process_count) {
				fprintf(stderr, "[scatter] Invalid size of vector (expected=%i, got=%lu)\n",__kaira__process_count, __kaira__value.size());
				exit(1);
			}
			if (ca::is_trivially_packable<int>()) {
				__kaira__thread->collective_scatter_root(111, &__kaira__value[0], sizeof(int));
			} else if (ca::fixed_size<int >() != 0) {
				size_t __kaira__size = ca::fixed_size<int >();
				ca::Packer __kaira__packer(__kaira__size * __kaira__process_count);
				ca::pack_with_step(__kaira__packer, __kaira__value, __kaira__size);
				__kaira__thread->collective_scatter_root(111, __kaira__packer.get_buffer(), __kaira__size);
				__kaira__packer.free();
			} else {
				int __kaira__process_id = __kaira__thread->get_process_id();
				ca::Packer __kaira__packer;
				int *__kaira__sizes = static_cast<int*>(alloca(sizeof(int) * __kaira__process_count));
				int *__kaira__displs = static_cast<int*>(alloca(sizeof(int) * (1 + __kaira__process_count)));
				__kaira__displs[0] = 0;
				for (int __kaira__i = 0; __kaira__i < __kaira__process_id; __kaira__i++) {
					__kaira__packer << __kaira__value[__kaira__i];
					__kaira__displs[__kaira__i + 1] = __kaira__packer.get_size();
					__kaira__sizes[__kaira__i] = __kaira__displs[__kaira__i + 1] - __kaira__displs[__kaira__i];
				}
				__kaira__displs[__kaira__process_id + 1] = __kaira__displs[__kaira__process_id];
				__kaira__sizes[__kaira__process_id] = 0;
				for (int __kaira__i = __kaira__process_id; __kaira__i < __kaira__process_count; __kaira__i++) {
					__kaira__packer << __kaira__value[__kaira__i];
					__kaira__displs[__kaira__i + 1] = __kaira__packer.get_size();
					__kaira__sizes[__kaira__i] = __kaira__displs[__kaira__i + 1] - __kaira__displs[__kaira__i];
				}
				__kaira__thread->collective_scatter_root(111, __kaira__sizes, sizeof(int));
				__kaira__thread->collective_scatterv_root(111, __kaira__packer.get_buffer(), __kaira__sizes, __kaira__displs);
				__kaira__packer.free();
			}
			__kaira__n->place_114.add(__kaira__value[__kaira__root]);
			__kaira__n->activate_transition_by_pos_id(2);
		} else {
			const size_t __kaira__size = sizeof(int);
			ca::Token<int > *__kaira__token = new ca::Token<int >;
			if (ca::is_trivially_packable<int>()) {
				__kaira__thread->collective_scatter_nonroot(111, __kaira__root, &__kaira__token->value, __kaira__size);
			} else if (ca::fixed_size<int >() != 0) {
				size_t __kaira__size = ca::fixed_size<int >();
				void *__kaira__mem = malloc(__kaira__size * __kaira__thread->get_process_count());
				__kaira__thread->collective_scatter_nonroot(111, __kaira__root, __kaira__mem, __kaira__size);
				ca::Unpacker __kaira__unpacker(__kaira__mem);
				__kaira__unpacker >> __kaira__token->value;
				free(__kaira__mem);
			} else {
				int __kaira__size;
				__kaira__thread->collective_scatter_nonroot(111, __kaira__root, &__kaira__size, sizeof(int));
				void *__kaira__mem = malloc(__kaira__size);
				__kaira__thread->collective_scatterv_nonroot(111, __kaira__root, __kaira__mem, __kaira__size);
				ca::Unpacker __kaira__unpacker(__kaira__mem);
				__kaira__unpacker >> __kaira__token->value;
				free(__kaira__mem);
			}
			__kaira__n->place_114.add_token(__kaira__token);
			__kaira__n->activate_transition_by_pos_id(2);
		}
		delete __kaira__token_1007;
		delete __kaira__token_1009;
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
ca::Binding* Transition_111::fire_phase1(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	// Inscription id=113 uid=1007 expr=lock
	ca::Token < int > *__kaira__token_1007;
	bool __kaira__inscription_if_1007;
	if (!(ctx.process_id() != 0)) {
		__kaira__inscription_if_1007 = false;
		__kaira__token_1007 = new ca::Token<int >;
		__kaira__token_1007->next = __kaira__token_1007;
		__kaira__token_1007->prev = __kaira__token_1007;
	} else {
		__kaira__inscription_if_1007 = true;
		__kaira__token_1007 = __kaira__n->place_109.begin();
		if (__kaira__token_1007 == NULL) return NULL;
		int &lock = __kaira__token_1007->value;
	}
	int &lock = __kaira__token_1007->value;
	// Inscription id=113 uid=1009 expr=list
	ca::Token < std::vector<int> > *__kaira__token_1009;
	int __kaira__root = 0;
	bool __kaira__inscription_if_1009;
	if (__kaira__root != __kaira__thread->get_process_id()) {
		__kaira__inscription_if_1009 = false;
		__kaira__token_1009 = new ca::Token<std::vector<int> >;
		__kaira__token_1009->next = __kaira__token_1009;
		__kaira__token_1009->prev = __kaira__token_1009;
	} else {
		__kaira__inscription_if_1009 = true;
		__kaira__token_1009 = __kaira__n->place_103.begin();
		if (__kaira__token_1009 == NULL) return NULL;
		std::vector<int> &list = __kaira__token_1009->value;
	}
	std::vector<int> &list = __kaira__token_1009->value;
	{
		{
			if (__kaira__inscription_if_1007) {
				__kaira__n->place_109.remove(__kaira__token_1007);
			}
			if (__kaira__inscription_if_1009) {
				__kaira__n->place_103.remove(__kaira__token_1009);
			}
		}
		Tokens_111 *__kaira__tokens = new Tokens_111();
		__kaira__tokens->token_1007 = __kaira__token_1007;
		__kaira__tokens->token_1009 = __kaira__token_1009;
		__kaira__tokens->blocked = true;
		__kaira__tokens->root = __kaira__root;
		__kaira__tokens->token_collective = NULL;
		std::vector<ca::Binding*> __kaira__bindings;
		int __kaira__bcount = __kaira__thread->collective_bindings(this, __kaira__bindings);
		int __kaira__process_count = __kaira__thread->get_process_count();
		if (__kaira__root < 0 || __kaira__root >= __kaira__process_count) {
			fprintf(stderr, "Collective transition started with invalid root; root=%i at process %i \n",__kaira__root, __kaira__thread->get_process_id());
			exit(1);
		}
		for (int __kaira__i = 0; __kaira__i < __kaira__thread->get_process_count(); __kaira__i++) {
			Tokens_111 *__kaira__t = static_cast<Tokens_111*>(__kaira__bindings[__kaira__i]);
			if (__kaira__t && __kaira__t->root != __kaira__root) {
				fprintf(stderr, "Collective transition started with different roots; root=%i at process %i and root=%i at process %i\n",__kaira__root, __kaira__thread->get_process_id(), __kaira__t->root, __kaira__i);
				exit(1);
			}
		}
		if (__kaira__bcount == __kaira__thread->get_process_count() - 1) {
			__kaira__bindings[__kaira__thread->get_process_id()] = __kaira__tokens;
			Tokens_111 *__kaira__rbinding = static_cast<Tokens_111*>(__kaira__bindings[__kaira__root]);
			ca::Token<int > *__kaira__token_1007 = __kaira__rbinding->token_1007;
			ca::Token<std::vector<int> > *__kaira__token_1009 = __kaira__rbinding->token_1009;
			int __kaira__root = __kaira__rbinding->root;
			int &lock = __kaira__token_1007->value;
			std::vector<int> &list = __kaira__token_1009->value;
			const std::vector<int > &__kaira__ccdata = list;
			if (__kaira__ccdata.size() != __kaira__thread->get_process_count()) {
				fprintf(stderr, "Invalid number of scattered elements (%lu)\n",__kaira__ccdata.size());
				exit(1);
			}
			for (int __kaira__i = 0; __kaira__i < __kaira__thread->get_process_count(); __kaira__i++) {
				Tokens_111 *__kaira__t = static_cast<Tokens_111*>(__kaira__bindings[__kaira__i]);
				__kaira__t->blocked = false;
				__kaira__t->token_collective = new ca::Token<int >(__kaira__ccdata[__kaira__i]);
			}
		}
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_111::fire_phase2(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net, ca::Binding *__kaira__binding)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_111 *__kaira__tokens = static_cast<Tokens_111*>(__kaira__binding);
	ca::Token<int > *__kaira__token_1007 = __kaira__tokens->token_1007;
	ca::Token<std::vector<int> > *__kaira__token_1009 = __kaira__tokens->token_1009;
	int __kaira__root = __kaira__tokens->root;
	int &lock = __kaira__token_1007->value;
	std::vector<int> &list = __kaira__token_1009->value;
	__kaira__n->activate_transition_by_pos_id(0);
	__kaira__n->place_114.add_token(__kaira__tokens->token_collective);
	__kaira__tokens->token_collective = NULL;
	delete __kaira__binding;
}
bool Transition_111::is_enable(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	// Inscription id=113 uid=1007 expr=lock
	ca::Token < int > *__kaira__token_1007;
	bool __kaira__inscription_if_1007;
	if (!(ctx.process_id() != 0)) {
		__kaira__inscription_if_1007 = false;
		__kaira__token_1007 = new ca::Token<int >;
		__kaira__token_1007->next = __kaira__token_1007;
		__kaira__token_1007->prev = __kaira__token_1007;
	} else {
		__kaira__inscription_if_1007 = true;
		__kaira__token_1007 = __kaira__n->place_109.begin();
		if (__kaira__token_1007 == NULL) return false;
		int &lock = __kaira__token_1007->value;
	}
	int &lock = __kaira__token_1007->value;
	// Inscription id=113 uid=1009 expr=list
	ca::Token < std::vector<int> > *__kaira__token_1009;
	int __kaira__root = 0;
	bool __kaira__inscription_if_1009;
	if (__kaira__root != __kaira__thread->get_process_id()) {
		__kaira__inscription_if_1009 = false;
		__kaira__token_1009 = new ca::Token<std::vector<int> >;
		__kaira__token_1009->next = __kaira__token_1009;
		__kaira__token_1009->prev = __kaira__token_1009;
	} else {
		__kaira__inscription_if_1009 = true;
		__kaira__token_1009 = __kaira__n->place_103.begin();
		if (__kaira__token_1009 == NULL) return false;
		std::vector<int> &list = __kaira__token_1009->value;
	}
	std::vector<int> &list = __kaira__token_1009->value;
	{
		return true;
	}
	return false;
}
bool Transition_111::is_blocked(ca::Binding *binding)
{
	Tokens_111 *tokens = static_cast<Tokens_111*>(binding);
	return tokens->blocked;
}
ca::FireResult Transition_102::full_fire(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_105.size();
		if (!(size == ctx.process_count())) return ca::NOT_ENABLED;
	}
	{
		{
		}
		__kaira__n->activate_transition_by_pos_id(1);
		ca::TokenList<int > data;
		__kaira__n->place_105.put_into(data);
		ca::Token <std::vector<int> > *__kaira__token_1003 = new ca::Token<std::vector<int> >;
		std::vector<int> &list = __kaira__token_1003->value;
		Vars_102 __kaira__vars(ctx,data,list);
		transition_user_fn_102(ctx, __kaira__vars);
		__kaira__n->place_103.add_token(__kaira__token_1003);
		__kaira__n->activate_transition_by_pos_id(0);
		{
			ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
			ca::pack(__kaira__packer, (1 ));
			__kaira__thread->send_multicast(ca::range(1, ctx.process_count()), __kaira__n, 110, 1, __kaira__packer);
		}
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
ca::Binding* Transition_102::fire_phase1(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_105.size();
		if (!(size == ctx.process_count())) return NULL;
	}
	{
		{
		}
		Tokens_102 *__kaira__tokens = new Tokens_102();
		__kaira__tokens->tokens_1002.overtake(__kaira__n->place_105);
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_102::fire_phase2(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net, ca::Binding *__kaira__binding)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_102 *__kaira__tokens = static_cast<Tokens_102*>(__kaira__binding);
	__kaira__n->activate_transition_by_pos_id(1);
	ca::TokenList<int > data;
	__kaira__tokens->tokens_1002.put_into(data);
	ca::Token <std::vector<int> > *__kaira__token_1003 = new ca::Token<std::vector<int> >;
	std::vector<int> &list = __kaira__token_1003->value;
	Vars_102 __kaira__vars(ctx,data,list);
	transition_user_fn_102(ctx, __kaira__vars);
	__kaira__n->place_103.add_token(__kaira__token_1003);
	__kaira__n->activate_transition_by_pos_id(0);
	{
		ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
		ca::pack(__kaira__packer, (1 ));
		__kaira__thread->send_multicast(ca::range(1, ctx.process_count()), __kaira__n, 110, 1, __kaira__packer);
	}
	delete __kaira__binding;
}
bool Transition_102::is_enable(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_105.size();
		if (!(size == ctx.process_count())) return false;
	}
	{
		return true;
	}
	return false;
}
ca::FireResult Transition_123::full_fire(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_114.size() < 1) return ca::NOT_ENABLED;
	// Inscription id=124 uid=1013 expr=x
	ca::Token < int > *__kaira__token_1013;
	__kaira__token_1013 = __kaira__n->place_114.begin();
	int &x = __kaira__token_1013->value;
	{
		{
			__kaira__n->place_114.remove(__kaira__token_1013);
		}
		__kaira__n->activate_transition_by_pos_id(2);
		if (0 == __kaira__thread->get_process_id()) {
			__kaira__n->place_128.add(x);
			__kaira__n->activate_transition_by_pos_id(3);
		} else {
			int __kaira__target = 0;
				ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
				ca::pack(__kaira__packer, (x));
				__kaira__thread->send(__kaira__target, __kaira__n, 129, 1, __kaira__packer);
			}
			delete __kaira__token_1013;
			return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
ca::Binding* Transition_123::fire_phase1(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_114.size() < 1) return NULL;
	// Inscription id=124 uid=1013 expr=x
	ca::Token < int > *__kaira__token_1013;
	__kaira__token_1013 = __kaira__n->place_114.begin();
	int &x = __kaira__token_1013->value;
	{
		{
			__kaira__n->place_114.remove(__kaira__token_1013);
		}
		Tokens_123 *__kaira__tokens = new Tokens_123();
		__kaira__tokens->token_1013 = __kaira__token_1013;
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_123::fire_phase2(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net, ca::Binding *__kaira__binding)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_123 *__kaira__tokens = static_cast<Tokens_123*>(__kaira__binding);
	ca::Token<int > *__kaira__token_1013 = __kaira__tokens->token_1013;
	int &x = __kaira__token_1013->value;
	__kaira__n->activate_transition_by_pos_id(2);
	if (0 == __kaira__thread->get_process_id()) {
		__kaira__n->place_128.add(x);
		__kaira__n->activate_transition_by_pos_id(3);
} else {
	int __kaira__target = 0;
		ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
		ca::pack(__kaira__packer, (x));
		__kaira__thread->send(__kaira__target, __kaira__n, 129, 1, __kaira__packer);
	}
	delete __kaira__binding;
}
bool Transition_123::is_enable(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_114.size() < 1) return false;
	// Inscription id=124 uid=1013 expr=x
	ca::Token < int > *__kaira__token_1013;
	__kaira__token_1013 = __kaira__n->place_114.begin();
	int &x = __kaira__token_1013->value;
	{
		return true;
	}
	return false;
}
ca::FireResult Transition_130::full_fire(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == ctx.process_count())) return ca::NOT_ENABLED;
	}
	{
		{
		}
		__kaira__n->activate_transition_by_pos_id(3);
		ca::TokenList<int > data;
		__kaira__n->place_128.put_into(data);
		Vars_130 __kaira__vars(ctx,data);
		transition_user_fn_130(ctx, __kaira__vars);
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
ca::Binding* Transition_130::fire_phase1(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == ctx.process_count())) return NULL;
	}
	{
		{
		}
		Tokens_130 *__kaira__tokens = new Tokens_130();
		__kaira__tokens->tokens_1018.overtake(__kaira__n->place_128);
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_130::fire_phase2(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net, ca::Binding *__kaira__binding)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_130 *__kaira__tokens = static_cast<Tokens_130*>(__kaira__binding);
	__kaira__n->activate_transition_by_pos_id(3);
	ca::TokenList<int > data;
	__kaira__tokens->tokens_1018.put_into(data);
	Vars_130 __kaira__vars(ctx,data);
	transition_user_fn_130(ctx, __kaira__vars);
	delete __kaira__binding;
}
bool Transition_130::is_enable(ca::ThreadBase *__kaira__thread, ca::NetBase *__kaira__net)
{
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == ctx.process_count())) return false;
	}
	{
		return true;
	}
	return false;
}
int main(int argc, char **argv)
{
	ca::project_description("<project library-octave=\"False\" library-rpc=\"False\" target_env=\"C++\"><configuration><build-option name=\"LIBS\" /><build-option name=\"CFLAGS\">-O0 -g</build-option></configuration><net id=\"101\" name=\"memory-leak-1\"><transition clock=\"False\" collective=\"False\" id=\"102\" label-x=\"-47.0\" label-y=\"-238.0\" name=\"\" priority=\"\" sx=\"70\" sy=\"36\" x=\"-82.0\" y=\"-256.0\"><guard x=\"-82.0\" y=\"-276.0\" /><code>\tvar.list = std::vector&lt;int&gt;(ctx.process_count());\n\tca::Token&lt;int&gt; *t = var.data.begin();\n\tint i = 0;\n\twhile (t != NULL) {\n\t\tvar.list[i] = t-&gt;value;\n\t\ti++;\n\t\tt = var.data.next(t);\n\t}\n</code></transition><place id=\"105\" label-x=\"279.0\" label-y=\"-238.0\" name=\"\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"279.0\" y=\"-238.0\"><place-type x=\"296.0\" y=\"-221.0\">int</place-type><init x=\"296.0\" y=\"-268.0\" /><code>\tfor (int i = 1; i &lt;= ctx.process_count(); i++) {\n\t\tplace.add(1);\n\t}\n</code><trace trace-tokens=\"False\" /></place><edge from_item=\"105\" id=\"107\" to_item=\"102\"><inscription x=\"14.0481481481\" y=\"-255.0\">[bulk, guard(size == ctx.process_count())] data</inscription></edge><place id=\"103\" label-x=\"-218.0\" label-y=\"-238.0\" name=\"\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-218.0\" y=\"-238.0\"><place-type x=\"-201.0\" y=\"-221.0\">std::vector&lt;int&gt;</place-type><init x=\"-201.0\" y=\"-268.0\" /><trace trace-tokens=\"False\" /></place><edge from_item=\"102\" id=\"108\" to_item=\"103\"><inscription x=\"-143.0\" y=\"-255.0\">list</inscription></edge><place id=\"109\" label-x=\"-334.0\" label-y=\"-234.0\" name=\"lock\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-334.0\" y=\"-234.0\"><place-type x=\"-317.0\" y=\"-217.0\">int</place-type><init x=\"-317.0\" y=\"-264.0\" /><trace trace-tokens=\"False\" /></place><edge from_item=\"102\" id=\"110\" to_item=\"109\"><inscription x=\"-317.394396339\" y=\"-317.198133153\">[multicast] 1 @ ca::range(1, ctx.process_count())</inscription><point x=\"-47.0\" y=\"-298.0\" /><point x=\"-332.0\" y=\"-298.0\" /></edge><transition clock=\"False\" collective=\"True\" id=\"111\" label-x=\"-277.0\" label-y=\"-120.0\" name=\"\" priority=\"10\" sx=\"70\" sy=\"36\" x=\"-312.0\" y=\"-138.0\"><guard x=\"-312.0\" y=\"-158.0\" /><root x=\"-272.0\" y=\"-98.0\">0</root></transition><edge from_item=\"109\" id=\"112\" to_item=\"111\"><inscription x=\"-496.5\" y=\"-177.217741935\">[if (ctx.process_id() != 0)] lock</inscription><point x=\"-335.0\" y=\"-119.0\" /></edge><edge from_item=\"103\" id=\"113\" to_item=\"111\"><inscription x=\"-206.5\" y=\"-172.0\">[root] list</inscription><point x=\"-217.0\" y=\"-120.0\" /></edge><place id=\"114\" label-x=\"-277.0\" label-y=\"-13.0\" name=\"\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-277.0\" y=\"-13.0\"><place-type x=\"-260.0\" y=\"4.0\">int</place-type><init x=\"-260.0\" y=\"-43.0\" /><trace trace-tokens=\"False\" /></place><edge from_item=\"111\" id=\"115\" to_item=\"114\"><inscription x=\"-265.947267218\" y=\"-65.7172596539\">[scatter] list</inscription></edge><transition clock=\"False\" collective=\"False\" id=\"123\" label-x=\"-161.0\" label-y=\"-13.0\" name=\"send\" priority=\"\" sx=\"70\" sy=\"36\" x=\"-196.0\" y=\"-31.0\"><guard x=\"-196.0\" y=\"-51.0\" /></transition><edge from_item=\"114\" id=\"124\" to_item=\"123\"><inscription x=\"-231.782222383\" y=\"-32.7333007335\">x</inscription></edge><place id=\"128\" label-x=\"-36.0\" label-y=\"-13.0\" name=\"\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-36.0\" y=\"-13.0\"><place-type x=\"-19.0\" y=\"4.0\">int</place-type><init x=\"-19.0\" y=\"-43.0\" /><trace trace-tokens=\"False\" /></place><edge from_item=\"123\" id=\"129\" to_item=\"128\"><inscription x=\"-103.343296028\" y=\"-32.1900482389\">x@0</inscription></edge><transition clock=\"False\" collective=\"False\" id=\"130\" label-x=\"278.0\" label-y=\"-13.0\" name=\"quit\" priority=\"\" sx=\"70\" sy=\"36\" x=\"243.0\" y=\"-31.0\"><guard x=\"243.0\" y=\"-51.0\" /><code>\tca::Token&lt;int&gt; *t = var.data.begin();\n\twhile (t != NULL) {\n\t\tprintf(\"%d \", t-&gt;value);\n\t\tt = var.data.next(t);\n\t}\n\tprintf(\"\\n\");\n\tctx.quit();\n</code></transition><edge from_item=\"128\" id=\"131\" to_item=\"130\"><inscription x=\"-6.01994828756\" y=\"-32.8901785058\">[bulk, guard(size == ctx.process_count())] data</inscription></edge></net></project>");
	std::vector<ca::Parameter*> parameters;

	ca::init(argc, argv, parameters, false);

	ca::NetDef *def_101 = new ca::NetDef(0, 101, spawn_101);
	def_101->register_transition(&transition_111);
	def_101->register_transition(&transition_102);
	def_101->register_transition(&transition_123);
	def_101->register_transition(&transition_130);
	ca::NetDef *defs[] = {def_101};
	ca::setup(1, defs, true);
	ca::spawn_net(0);
	ca::main();
	return 0;
}
#line 1 "*102/function"
void transition_user_fn_102(ca::Context &ctx, Vars_102 &var)
{
	var.list = std::vector<int>(ctx.process_count());
	ca::Token<int> *t = var.data.begin();
	int i = 0;
	while (t != NULL) {
		var.list[i] = t->value;
		i++;
		t = var.data.next(t);
	}
}
#line 1 "*130/function"
void transition_user_fn_130(ca::Context &ctx, Vars_130 &var)
{
	ca::Token<int> *t = var.data.begin();
	while (t != NULL) {
		printf("%d ", t->value);
		t = var.data.next(t);
	}
	printf("\n");
	ctx.quit();
}
#line 1 "*105/init_function"
void place_user_fn_105(ca::Context &ctx, ca::TokenList<int > &place)
{
	for (int i = 1; i <= ctx.process_count(); i++) {
		place.add(1);
	}
}
