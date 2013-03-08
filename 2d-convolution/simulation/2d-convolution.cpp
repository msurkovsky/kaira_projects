/* This file is automatically generated
   do not edit this file directly! */

#include <cailie.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

struct param
{
	static ca::ParameterInt width;
	static ca::ParameterInt divide_x;
	static ca::ParameterInt divide_y;
	static ca::ParameterInt height;
};

#line 1 "*head"
#include <matrix.h>

namespace ca {

	std::string token_name(const Matrix<float> &m) {
		return "matrix";
	}
	
	void pack(Packer &packer, Matrix<float> &m) {
		pack(packer, m.get_size_of_serialized_data());
		pack(packer, m.serialize(), m.get_size_of_serialized_data());
	}
	
	template<> Matrix<float> unpack(Unpacker &unpacker) {
		unsigned int size_of_data = unpack<unsigned int>(unpacker);
		char *mem = (char *) unpack(unpacker, size_of_data);
		Matrix<float> matrix;
		matrix.deserialize(mem);
		return matrix;
	}
}
#line 41 __BASE_FILE__

ca::ParameterInt param::width("width", "Width of matrix", ca::PARAMETER_MANDATORY);
ca::ParameterInt param::divide_x("divide_x", "divide in along x axes", ca::PARAMETER_MANDATORY);
ca::ParameterInt param::divide_y("divide_y", "divide along y axes", ca::PARAMETER_MANDATORY);
ca::ParameterInt param::height("height", "height of matrix", ca::PARAMETER_MANDATORY);
#line 1 "*102/init_function"
void place_user_fn_102(ca::Context &ctx, ca::TokenList<Matrix<float> > &place)
{
	Matrix<float> matrix(param::width(), param::height());
	for (unsigned int i = 0; i < param::width(); i++) {
		for (unsigned int j = 0; j < param::height(); j++) {
			matrix.set(i, j, 2.0);
		}
	}
	place.add(matrix);
}
#line 58 __BASE_FILE__
#line 1 "*109/init_function"
void place_user_fn_109(ca::Context &ctx, ca::TokenList<Matrix<float> > &place)
{
	int mask_width = 3, mask_height = 3;
	float m[] = {
		0.0, 1.0, 0.0,
		1.0, 0.0, 1.0,
		0.0, 1.0, 0.0,
	};
	
	Matrix<float> mask(mask_width, mask_height, m);
	place.add(mask);
}
#line 72 __BASE_FILE__
class Vars_104 {
	public:
	Vars_104(ca::TokenList<Matrix<float> > &blocks,ca::Context &ctx,Matrix<float> &mask,Matrix<float> &matrix) : blocks(blocks),ctx(ctx),mask(mask),matrix(matrix) {
	}
	ca::TokenList<Matrix<float> > &blocks;
	ca::Context &ctx;
	Matrix<float> &mask;
	Matrix<float> &matrix;
};
class Tokens_104 {
	public:
	ca::Token<Matrix<float> > *token_1001;
	ca::Token<Matrix<float> > *token_1003;
};
class Transition_104  : public ca::TransitionDef {
	public:
	int get_id() { return 104; }
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	void* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, void *data);
	void cleanup_binding(void *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_104 transition_104;

class Tokens_115 {
	public:
	ca::Token<int > *token_1009;
	ca::Token<Matrix<float> > *token_1011;
};
class Transition_115  : public ca::TransitionDef {
	public:
	int get_id() { return 115; }
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	void* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, void *data);
	void cleanup_binding(void *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_115 transition_115;

class Vars_125 {
	public:
	Vars_125(Matrix<float> &block,ca::Context &ctx,Matrix<float> &mask) : block(block),ctx(ctx),mask(mask) {
	}
	Matrix<float> &block;
	ca::Context &ctx;
	Matrix<float> &mask;
};
class Tokens_125 {
	public:
	ca::Token<Matrix<float> > *token_1017;
	ca::Token<Matrix<float> > *token_1019;
};
class Transition_125  : public ca::TransitionDef {
	public:
	int get_id() { return 125; }
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	void* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, void *data);
	void cleanup_binding(void *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_125 transition_125;

class Vars_130 {
	public:
	Vars_130(ca::TokenList<Matrix<float> > &blocks,std::vector<int > &blocks_origins,ca::Context &ctx,Matrix<float> &mask) : blocks(blocks),blocks_origins(blocks_origins),ctx(ctx),mask(mask) {
	}
	ca::TokenList<Matrix<float> > &blocks;
	std::vector<int > &blocks_origins;
	ca::Context &ctx;
	Matrix<float> &mask;
};
class Tokens_130 {
	public:
	ca::Token<Matrix<float> > *token_1027;
	ca::TokenList<Matrix<float> > tokens_1026;
	std::vector<int> origins_1026;
};
class Transition_130  : public ca::TransitionDef {
	public:
	int get_id() { return 130; }
	ca::FireResult full_fire(ca::ThreadBase *thread, ca::NetBase *net);
	void* fire_phase1(ca::ThreadBase *thread, ca::NetBase *net);
	void fire_phase2(ca::ThreadBase *thread, ca::NetBase *net, void *data);
	void cleanup_binding(void *data);
	bool is_enable(ca::ThreadBase *thread, ca::NetBase *net);
};
static Transition_130 transition_130;

class Net_101  : public ca::Net {
	public:
	Net_101(ca::NetDef * def,ca::Thread * thread) : ca::Net(def, thread) {
	}
	ca::TokenList<Matrix<float> > place_102;
	ca::TokenList<Matrix<float> > place_107;
	ca::TokenList<Matrix<float> > place_109;
	ca::TokenList<int > place_116;
	ca::TokenList<Matrix<float> > place_123;
	ca::TokenList<Matrix<float> > place_128;
	std::deque<int> place_128_origin;
	void write_reports_content(ca::Thread *thread, ca::Output &output) {
		output.child("place");
		output.set("id", 102);
		{
			ca::Token<Matrix<float> > *t = place_102.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_102.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 107);
		{
			ca::Token<Matrix<float> > *t = place_107.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_107.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 109);
		{
			ca::Token<Matrix<float> > *t = place_109.begin();
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
		output.set("id", 116);
		{
			ca::Token<int > *t = place_116.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_116.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 123);
		{
			ca::Token<Matrix<float> > *t = place_123.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.back();
					t = t->next;
				} while (t != place_123.begin());
			}
		}
		output.back();
		output.child("place");
		output.set("id", 128);
		{
			int i = 0;
			ca::Token<Matrix<float> > *t = place_128.begin();
			if (t) {
				do {
					output.child("token");
					output.set("value", ca::token_name(t->value));
					output.set("origin", ca::to_string(place_128_origin[i]));
					i++;
					output.back();
					t = t->next;
				} while (t != place_128.begin());
			}
		}
		output.back();
	}
	void receive(ca::ThreadBase *__kaira__thread, int from_process, int place_pos, ca::Unpacker &unpacker) {
		switch(place_pos) {
		case 4:
			this->place_123.add(ca::unpack<Matrix<float> >(unpacker));
			this->activate_transition_by_pos_id(2);
			break;
		case 5:
			this->place_128_origin.push_back(from_process);
			this->place_128.add(ca::unpack<Matrix<float> >(unpacker));
			this->activate_transition_by_pos_id(3);
			break;
		}
	}
};
ca::NetBase * spawn_101(ca::ThreadBase *__kaira__thread, ca::NetDef *__kaira__def) {
	Net_101 *__kaira__net = new Net_101(__kaira__def, (ca::Thread*) __kaira__thread);
	ca::Context ctx(__kaira__thread, __kaira__net);
	int __kaira__pid = __kaira__thread->get_process_id();
	std::vector<int> __kaira__area_106;
	__kaira__area_106.push_back(0);
	std::vector<int> __kaira__area_112 = ca::range(0, ctx.process_count());
	if (std::find(__kaira__area_106.begin(), __kaira__area_106.end(), __kaira__pid) != __kaira__area_106.end()) {
		place_user_fn_102(ctx, __kaira__net->place_102);
	}
	if (std::find(__kaira__area_112.begin(), __kaira__area_112.end(), __kaira__pid) != __kaira__area_112.end()) {
		place_user_fn_109(ctx, __kaira__net->place_109);
	}
	if (__kaira__pid == 0) {
		__kaira__net->place_116.add(0);
	}
	return __kaira__net;
}
#line 1 "*104/function"
void transition_user_fn_104(ca::Context &ctx, Vars_104 &var)
{
	unsigned int x_overlay = var.mask.get_width() / 2;
	unsigned int y_overlay = var.mask.get_height() / 2;

	unsigned int count = param::divide_x() * param::divide_y();	
	Matrix<float> *matrices = var.matrix.divide(
		param::divide_x(), param::divide_y(),
		x_overlay, y_overlay);
		
	for (unsigned int i = 0; i < count; i++) {
		var.blocks.add(matrices[i]);
	}
}
#line 311 __BASE_FILE__
ca::FireResult Transition_104::full_fire(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_102.size() < 1) return ca::NOT_ENABLED;
	if (__kaira__n->place_109.size() < 1) return ca::NOT_ENABLED;
	// Edge id=105 uid=1001 expr=matrix
	ca::Token < Matrix<float> > *__kaira__token_1001 =  __kaira__n->place_102.begin();
	// Edge id=114 uid=1003 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1003 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1003->value;
	Matrix<float> &matrix = __kaira__token_1001->value;
	{
		{
			__kaira__n->place_102.remove(__kaira__token_1001);
			__kaira__n->place_109.remove(__kaira__token_1003);
		}
		__kaira__n->activate_transition_by_pos_id(0);
		ca::TokenList<Matrix<float> > blocks; // Fresh variable
		__kaira__n->unlock();
		Vars_104 vars(blocks,ctx,mask,matrix);
		transition_user_fn_104(ctx, vars);
		bool __kaira__lock = false;
		if (!__kaira__lock) {
			__kaira__n->lock();
			__kaira__lock = true;
		}
		__kaira__n->place_107.overtake(blocks);
		__kaira__n->activate_transition_by_pos_id(1);
		if (!__kaira__lock) {
			__kaira__n->lock();
			__kaira__lock = true;
		}
		__kaira__n->place_109.add_token(__kaira__token_1003);
		__kaira__n->activate_transition_by_pos_id(0);
		__kaira__n->activate_transition_by_pos_id(3);
		__kaira__n->activate_transition_by_pos_id(2);
		if (__kaira__lock) __kaira__n->unlock();
		delete __kaira__token_1001;
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
void *Transition_104::fire_phase1(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_102.size() < 1) return NULL;
	if (__kaira__n->place_109.size() < 1) return NULL;
	// Edge id=105 uid=1001 expr=matrix
	ca::Token < Matrix<float> > *__kaira__token_1001 =  __kaira__n->place_102.begin();
	// Edge id=114 uid=1003 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1003 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1003->value;
	Matrix<float> &matrix = __kaira__token_1001->value;
	{
		{
			__kaira__n->place_102.remove(__kaira__token_1001);
			__kaira__n->place_109.remove(__kaira__token_1003);
		}
		Tokens_104 *__kaira__tokens = new Tokens_104();
		__kaira__tokens->token_1001 = __kaira__token_1001;
		__kaira__tokens->token_1003 = __kaira__token_1003;
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_104::fire_phase2(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net, void *__kaira__data)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_104 *__kaira__tokens = (Tokens_104*) __kaira__data;
	Matrix<float> mask = __kaira__tokens->token_1003->value;
	Matrix<float> matrix = __kaira__tokens->token_1001->value;
	__kaira__n->activate_transition_by_pos_id(0);
	ca::TokenList<Matrix<float> > blocks; // Fresh variable
	Vars_104 vars(blocks,ctx,mask,matrix);
	transition_user_fn_104(ctx, vars);
	__kaira__n->place_107.overtake(blocks);
	__kaira__n->activate_transition_by_pos_id(1);
	__kaira__n->place_109.add(mask);
	__kaira__n->activate_transition_by_pos_id(0);
	__kaira__n->activate_transition_by_pos_id(3);
	__kaira__n->activate_transition_by_pos_id(2);
}
void Transition_104::cleanup_binding(void *data)
{
	Tokens_104 *tokens = (Tokens_104*) data;
	delete tokens->token_1001;
	delete tokens->token_1003;
	delete tokens;
}
bool Transition_104::is_enable(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_102.size() < 1) return false;
	if (__kaira__n->place_109.size() < 1) return false;
	// Edge id=105 uid=1001 expr=matrix
	ca::Token < Matrix<float> > *__kaira__token_1001 =  __kaira__n->place_102.begin();
	// Edge id=114 uid=1003 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1003 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1003->value;
	Matrix<float> &matrix = __kaira__token_1001->value;
	{
		return true;
	}
	return false;
}
ca::FireResult Transition_115::full_fire(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_116.size() < 1) return ca::NOT_ENABLED;
	if (__kaira__n->place_107.size() < 1) return ca::NOT_ENABLED;
	// Edge id=119 uid=1009 expr=c
	ca::Token < int > *__kaira__token_1009 =  __kaira__n->place_116.begin();
	// Edge id=122 uid=1011 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1011 =  __kaira__n->place_107.begin();
	int &c = __kaira__token_1009->value;
	Matrix<float> &block = __kaira__token_1011->value;
	{
		{
			__kaira__n->place_116.remove(__kaira__token_1009);
			__kaira__n->place_107.remove(__kaira__token_1011);
		}
		__kaira__n->activate_transition_by_pos_id(1);
		bool __kaira__lock = true;
		if (!__kaira__lock) {
			__kaira__n->lock();
			__kaira__lock = true;
		}
		__kaira__n->place_116.add(c+1);
		__kaira__n->activate_transition_by_pos_id(1);
		if (c == __kaira__thread->get_process_id()) {
			if (!__kaira__lock) {
				__kaira__n->lock();
				__kaira__lock = true;
			}
			__kaira__n->place_123.add(block);
			__kaira__n->activate_transition_by_pos_id(2);
		} else {
			if (__kaira__lock) {
				__kaira__n->unlock();
				__kaira__lock = false;
			}
			ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
			ca::pack(__kaira__packer, block);
			__kaira__thread->multisend(c, __kaira__n, 4, 1, __kaira__packer);
		}
		if (__kaira__lock) __kaira__n->unlock();
		delete __kaira__token_1009;
		delete __kaira__token_1011;
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
void *Transition_115::fire_phase1(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_116.size() < 1) return NULL;
	if (__kaira__n->place_107.size() < 1) return NULL;
	// Edge id=119 uid=1009 expr=c
	ca::Token < int > *__kaira__token_1009 =  __kaira__n->place_116.begin();
	// Edge id=122 uid=1011 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1011 =  __kaira__n->place_107.begin();
	int &c = __kaira__token_1009->value;
	Matrix<float> &block = __kaira__token_1011->value;
	{
		{
			__kaira__n->place_116.remove(__kaira__token_1009);
			__kaira__n->place_107.remove(__kaira__token_1011);
		}
		Tokens_115 *__kaira__tokens = new Tokens_115();
		__kaira__tokens->token_1009 = __kaira__token_1009;
		__kaira__tokens->token_1011 = __kaira__token_1011;
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_115::fire_phase2(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net, void *__kaira__data)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_115 *__kaira__tokens = (Tokens_115*) __kaira__data;
	int c = __kaira__tokens->token_1009->value;
	Matrix<float> block = __kaira__tokens->token_1011->value;
	__kaira__n->activate_transition_by_pos_id(1);
	__kaira__n->place_116.add(c+1);
	__kaira__n->activate_transition_by_pos_id(1);
	if (c == __kaira__thread->get_process_id()) {
		__kaira__n->place_123.add(block);
		__kaira__n->activate_transition_by_pos_id(2);
	} else {
		ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
		ca::pack(__kaira__packer, block);
		__kaira__thread->multisend(c, __kaira__n, 4, 1, __kaira__packer);
	}
}
void Transition_115::cleanup_binding(void *data)
{
	Tokens_115 *tokens = (Tokens_115*) data;
	delete tokens->token_1009;
	delete tokens->token_1011;
	delete tokens;
}
bool Transition_115::is_enable(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_116.size() < 1) return false;
	if (__kaira__n->place_107.size() < 1) return false;
	// Edge id=119 uid=1009 expr=c
	ca::Token < int > *__kaira__token_1009 =  __kaira__n->place_116.begin();
	// Edge id=122 uid=1011 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1011 =  __kaira__n->place_107.begin();
	int &c = __kaira__token_1009->value;
	Matrix<float> &block = __kaira__token_1011->value;
	{
		return true;
	}
	return false;
}
#line 1 "*125/function"
void transition_user_fn_125(ca::Context &ctx, Vars_125 &var)
{
	var.block.convolve(var.mask);
}
#line 549 __BASE_FILE__
ca::FireResult Transition_125::full_fire(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_123.size() < 1) return ca::NOT_ENABLED;
	if (__kaira__n->place_109.size() < 1) return ca::NOT_ENABLED;
	// Edge id=126 uid=1017 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1017 =  __kaira__n->place_123.begin();
	// Edge id=127 uid=1019 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1019 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1019->value;
	Matrix<float> &block = __kaira__token_1017->value;
	{
		{
			__kaira__n->place_123.remove(__kaira__token_1017);
			__kaira__n->place_109.remove(__kaira__token_1019);
		}
		__kaira__n->activate_transition_by_pos_id(2);
		__kaira__n->unlock();
		Vars_125 vars(block,ctx,mask);
		transition_user_fn_125(ctx, vars);
		bool __kaira__lock = false;
		if (0 == __kaira__thread->get_process_id()) {
			if (!__kaira__lock) {
				__kaira__n->lock();
				__kaira__lock = true;
			}
			__kaira__n->place_128_origin.push_back(__kaira__thread->get_process_id());
			__kaira__n->place_128.add(block);
			__kaira__n->activate_transition_by_pos_id(3);
		} else {
			if (__kaira__lock) {
				__kaira__n->unlock();
				__kaira__lock = false;
			}
			ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
			ca::pack(__kaira__packer, block);
			__kaira__thread->multisend(0, __kaira__n, 5, 1, __kaira__packer);
		}
		if (!__kaira__lock) {
			__kaira__n->lock();
			__kaira__lock = true;
		}
		__kaira__n->place_109.add_token(__kaira__token_1019);
		__kaira__n->activate_transition_by_pos_id(0);
		__kaira__n->activate_transition_by_pos_id(3);
		__kaira__n->activate_transition_by_pos_id(2);
		if (__kaira__lock) __kaira__n->unlock();
		delete __kaira__token_1017;
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
void *Transition_125::fire_phase1(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_123.size() < 1) return NULL;
	if (__kaira__n->place_109.size() < 1) return NULL;
	// Edge id=126 uid=1017 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1017 =  __kaira__n->place_123.begin();
	// Edge id=127 uid=1019 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1019 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1019->value;
	Matrix<float> &block = __kaira__token_1017->value;
	{
		{
			__kaira__n->place_123.remove(__kaira__token_1017);
			__kaira__n->place_109.remove(__kaira__token_1019);
		}
		Tokens_125 *__kaira__tokens = new Tokens_125();
		__kaira__tokens->token_1017 = __kaira__token_1017;
		__kaira__tokens->token_1019 = __kaira__token_1019;
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_125::fire_phase2(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net, void *__kaira__data)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_125 *__kaira__tokens = (Tokens_125*) __kaira__data;
	Matrix<float> mask = __kaira__tokens->token_1019->value;
	Matrix<float> block = __kaira__tokens->token_1017->value;
	__kaira__n->activate_transition_by_pos_id(2);
	Vars_125 vars(block,ctx,mask);
	transition_user_fn_125(ctx, vars);
	if (0 == __kaira__thread->get_process_id()) {
		__kaira__n->place_128_origin.push_back(__kaira__thread->get_process_id());
		__kaira__n->place_128.add(block);
		__kaira__n->activate_transition_by_pos_id(3);
	} else {
		ca::Packer __kaira__packer(ca::PACKER_DEFAULT_SIZE, ca::RESERVED_PREFIX);
		ca::pack(__kaira__packer, block);
		__kaira__thread->multisend(0, __kaira__n, 5, 1, __kaira__packer);
	}
	__kaira__n->place_109.add(mask);
	__kaira__n->activate_transition_by_pos_id(0);
	__kaira__n->activate_transition_by_pos_id(3);
	__kaira__n->activate_transition_by_pos_id(2);
}
void Transition_125::cleanup_binding(void *data)
{
	Tokens_125 *tokens = (Tokens_125*) data;
	delete tokens->token_1017;
	delete tokens->token_1019;
	delete tokens;
}
bool Transition_125::is_enable(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_123.size() < 1) return false;
	if (__kaira__n->place_109.size() < 1) return false;
	// Edge id=126 uid=1017 expr=block
	ca::Token < Matrix<float> > *__kaira__token_1017 =  __kaira__n->place_123.begin();
	// Edge id=127 uid=1019 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1019 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1019->value;
	Matrix<float> &block = __kaira__token_1017->value;
	{
		return true;
	}
	return false;
}
#line 1 "*130/function"
void transition_user_fn_130(ca::Context &ctx, Vars_130 &var)
{
	unsigned int size = param::divide_x() * param::divide_y();
	Matrix<float> *matrices = new Matrix<float>[size];
	
	unsigned int x_overlay = var.mask.get_width() / 2;
	unsigned int y_overlay = var.mask.get_height() / 2;

	int i = 0;		
	for (ca::Token<Matrix<float> > *t = var.blocks.begin(); t != NULL; t = var.blocks.next(t)) {
		matrices[var.blocks_origins[i]] = t->value;
		i++;
	}
	
	Matrix<float> matrix = Matrix<float>::join(
		param::width(), param::height(),
		param::divide_x(), param::divide_y(),
		matrices,
		x_overlay,
		y_overlay);
		
	for (unsigned int i = 0; i < param::width(); i++) {
		for (unsigned int j = 0; j < param::height(); j++) {
			printf("%.2f ", matrix.get(i, j));
		}
		printf("\n");
	}
	
	delete [] matrices;
	ctx.quit();
}
#line 711 __BASE_FILE__
ca::FireResult Transition_130::full_fire(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_109.size() < 1) return ca::NOT_ENABLED;
	// Edge id=132 uid=1027 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1027 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1027->value;
	std::vector<int> blocks_origins(__kaira__n->place_128_origin.begin(), __kaira__n->place_128_origin.end());
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == (param::divide_x() * param::divide_y()))) return ca::NOT_ENABLED;
	}
	{
		{
			__kaira__n->place_109.remove(__kaira__token_1027);
		}
		__kaira__n->place_128_origin.clear();
		__kaira__n->activate_transition_by_pos_id(3);
		ca::TokenList<Matrix<float> > blocks(__kaira__n->place_128, true);
		__kaira__n->unlock();
		Vars_130 vars(blocks,blocks_origins,ctx,mask);
		transition_user_fn_130(ctx, vars);
		bool __kaira__lock = false;
		if (__kaira__lock) __kaira__n->unlock();
		delete __kaira__token_1027;
		return ca::TRANSITION_FIRED;
	}
	return ca::NOT_ENABLED;
}
void *Transition_130::fire_phase1(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_109.size() < 1) return NULL;
	// Edge id=132 uid=1027 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1027 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1027->value;
	std::vector<int> blocks_origins(__kaira__n->place_128_origin.begin(), __kaira__n->place_128_origin.end());
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == (param::divide_x() * param::divide_y()))) return NULL;
	}
	{
		{
			__kaira__n->place_109.remove(__kaira__token_1027);
		}
		__kaira__n->place_128_origin.clear();
		Tokens_130 *__kaira__tokens = new Tokens_130();
		__kaira__tokens->token_1027 = __kaira__token_1027;
		__kaira__tokens->tokens_1026.overtake(__kaira__n->place_128);
		__kaira__tokens->origins_1026 = blocks_origins;
		return __kaira__tokens;
	}
	return NULL;
}
void Transition_130::fire_phase2(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net, void *__kaira__data)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	Tokens_130 *__kaira__tokens = (Tokens_130*) __kaira__data;
	Matrix<float> mask = __kaira__tokens->token_1027->value;
	std::vector<int> blocks_origins = __kaira__tokens->origins_1026;
	__kaira__n->activate_transition_by_pos_id(3);
	ca::TokenList<Matrix<float> > blocks(__kaira__tokens->tokens_1026, false);
	Vars_130 vars(blocks,blocks_origins,ctx,mask);
	transition_user_fn_130(ctx, vars);
}
void Transition_130::cleanup_binding(void *data)
{
	Tokens_130 *tokens = (Tokens_130*) data;
	delete tokens->token_1027;
	delete tokens;
}
bool Transition_130::is_enable(ca::ThreadBase *__kaira__t, ca::NetBase *__kaira__net)
{
	ca::Thread *__kaira__thread = (ca::Thread*) __kaira__t;
	ca::Context ctx(__kaira__thread, __kaira__net);
	Net_101 *__kaira__n = (Net_101*) __kaira__net;
	if (__kaira__n->place_109.size() < 1) return false;
	// Edge id=132 uid=1027 expr=mask
	ca::Token < Matrix<float> > *__kaira__token_1027 =  __kaira__n->place_109.begin();
	Matrix<float> &mask = __kaira__token_1027->value;
	std::vector<int> blocks_origins(__kaira__n->place_128_origin.begin(), __kaira__n->place_128_origin.end());
	{
		size_t size = __kaira__n->place_128.size();
		if (!(size == (param::divide_x() * param::divide_y()))) return false;
	}
	{
		return true;
	}
	return false;
}
int main(int argc, char **argv)
{
	ca::project_description("<project target_env=\"C++\"><configuration><parameter default=\"24\" description=\"Width of matrix\" name=\"width\" policy=\"mandatory\" type=\"unsigned int\" /><parameter default=\"24\" description=\"height of matrix\" name=\"height\" policy=\"mandatory\" type=\"unsigned int\" /><parameter default=\"1\" description=\"divide in along x axes\" name=\"divide_x\" policy=\"mandatory\" type=\"int\" /><parameter default=\"1\" description=\"divide along y axes\" name=\"divide_y\" policy=\"mandatory\" type=\"int\" /><build-option name=\"CC\">g++</build-option><build-option name=\"LIBS\" /><build-option name=\"CFLAGS\">-O2</build-option><head-code>#include &lt;matrix.h&gt;\n\nnamespace ca {\n\n\tstd::string token_name(const Matrix&lt;float&gt; &amp;m) {\n\t\treturn \"matrix\";\n\t}\n\t\n\tvoid pack(Packer &amp;packer, Matrix&lt;float&gt; &amp;m) {\n\t\tpack(packer, m.get_size_of_serialized_data());\n\t\tpack(packer, m.serialize(), m.get_size_of_serialized_data());\n\t}\n\t\n\ttemplate&lt;&gt; Matrix&lt;float&gt; unpack(Unpacker &amp;unpacker) {\n\t\tunsigned int size_of_data = unpack&lt;unsigned int&gt;(unpacker);\n\t\tchar *mem = (char *) unpack(unpacker, size_of_data);\n\t\tMatrix&lt;float&gt; matrix;\n\t\tmatrix.deserialize(mem);\n\t\treturn matrix;\n\t}\n}</head-code></configuration><net id=\"101\" name=\"Main\" net-type=\"main\"><edge from_item=\"102\" id=\"105\" inscription=\"matrix\" inscription_x=\"-410.858224533\" inscription_y=\"-223.998006572\" to_item=\"104\" /><edge from_item=\"104\" id=\"108\" inscription=\"[bulk] blocks\" inscription_x=\"-242.538961039\" inscription_y=\"-222.0\" to_item=\"107\" /><edge bidirectional=\"true\" from_item=\"109\" id=\"114\" inscription=\"mask\" inscription_x=\"-356.410977678\" inscription_y=\"-84.4351921717\" to_item=\"104\"><point x=\"-331\" y=\"-69\" /></edge><edge from_item=\"116\" id=\"119\" inscription=\"c\" inscription_x=\"-204.516728625\" inscription_y=\"-132.033457249\" to_item=\"115\"><point x=\"-233\" y=\"-135\" /></edge><edge from_item=\"115\" id=\"120\" inscription=\"c+1\" inscription_x=\"-253.231255956\" inscription_y=\"-50.3085111586\" to_item=\"116\"><point x=\"-227\" y=\"-38\" /></edge><edge from_item=\"107\" id=\"122\" inscription=\"block\" inscription_x=\"-139.0\" inscription_y=\"-157.0\" to_item=\"115\" /><edge from_item=\"115\" id=\"124\" inscription=\"block@c\" inscription_x=\"-130.007712939\" inscription_y=\"-38.6841658307\" to_item=\"123\" /><edge from_item=\"123\" id=\"126\" inscription=\"block\" inscription_x=\"-221.0\" inscription_y=\"13.0\" to_item=\"125\" /><edge bidirectional=\"true\" from_item=\"109\" id=\"127\" inscription=\"mask\" inscription_x=\"-382.503863801\" inscription_y=\"13.0\" to_item=\"125\"><point x=\"-428\" y=\"26\" /></edge><edge from_item=\"125\" id=\"129\" inscription=\"block@0\" inscription_x=\"-270.509345295\" inscription_y=\"59.0321693297\" to_item=\"128\" /><edge from_item=\"128\" id=\"131\" inscription=\"[bulk, origin, guard(size == (param::divide_x() * param::divide_y()))] blocks\" inscription_x=\"-105.00420102\" inscription_y=\"140.754557222\" to_item=\"130\" /><edge from_item=\"109\" id=\"132\" inscription=\"mask\" inscription_x=\"-384.0\" inscription_y=\"172.0\" to_item=\"130\"><point x=\"-531\" y=\"188\" /></edge><place id=\"102\" init_string=\"\" name=\"\" place_type=\"Matrix&lt;float&gt;\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-564\" y=\"-205\"><code>\tMatrix&lt;float&gt; matrix(param::width(), param::height());\n\tfor (unsigned int i = 0; i &lt; param::width(); i++) {\n\t\tfor (unsigned int j = 0; j &lt; param::height(); j++) {\n\t\t\tmatrix.set(i, j, 2.0);\n\t\t}\n\t}\n\tplace.add(matrix);\n</code></place><transition guard=\"\" id=\"104\" name=\"divide\" sx=\"70\" sy=\"35\" x=\"-333\" y=\"-206\"><code>\tunsigned int x_overlay = var.mask.get_width() / 2;\n\tunsigned int y_overlay = var.mask.get_height() / 2;\n\n\tunsigned int count = param::divide_x() * param::divide_y();\t\n\tMatrix&lt;float&gt; *matrices = var.matrix.divide(\n\t\tparam::divide_x(), param::divide_y(),\n\t\tx_overlay, y_overlay);\n\t\t\n\tfor (unsigned int i = 0; i &lt; count; i++) {\n\t\tvar.blocks.add(matrices[i]);\n\t}\n</code></transition><place id=\"107\" init_string=\"\" name=\"\" place_type=\"Matrix&lt;float&gt;\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-161\" y=\"-206\" /><place id=\"109\" init_string=\"\" name=\"convolution mask\" place_type=\"Matrix&lt;float&gt;\" radius=\"20\" sx=\"73\" sy=\"0\" x=\"-572\" y=\"-70\"><code>\tint mask_width = 3, mask_height = 3;\n\tfloat m[] = {\n\t\t0.0, 1.0, 0.0,\n\t\t1.0, 0.0, 1.0,\n\t\t0.0, 1.0, 0.0,\n\t};\n\t\n\tMatrix&lt;float&gt; mask(mask_width, mask_height, m);\n\tplace.add(mask);\n</code></place><transition guard=\"\" id=\"115\" name=\"distribute\" sx=\"70\" sy=\"35\" x=\"-160\" y=\"-90\" /><place id=\"116\" init_string=\"[0]\" name=\"counter\" place_type=\"int\" radius=\"20\" sx=\"7\" sy=\"0\" x=\"-276\" y=\"-86\" /><place id=\"123\" init_string=\"\" name=\"\" place_type=\"Matrix&lt;float&gt;\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-158\" y=\"25\" /><transition guard=\"\" id=\"125\" name=\"convolve\" sx=\"70\" sy=\"35\" x=\"-303\" y=\"27\"><code>\tvar.block.convolve(var.mask);\n</code></transition><place id=\"128\" init_string=\"\" name=\"\" place_type=\"Matrix&lt;float&gt;\" radius=\"20\" sx=\"0\" sy=\"0\" x=\"-302\" y=\"109\" /><transition guard=\"\" id=\"130\" name=\"join\" sx=\"70\" sy=\"35\" x=\"-301\" y=\"187\"><code>\tunsigned int size = param::divide_x() * param::divide_y();\n\tMatrix&lt;float&gt; *matrices = new Matrix&lt;float&gt;[size];\n\t\n\tunsigned int x_overlay = var.mask.get_width() / 2;\n\tunsigned int y_overlay = var.mask.get_height() / 2;\n\n\tint i = 0;\t\t\n\tfor (ca::Token&lt;Matrix&lt;float&gt; &gt; *t = var.blocks.begin(); t != NULL; t = var.blocks.next(t)) {\n\t\tmatrices[var.blocks_origins[i]] = t-&gt;value;\n\t\ti++;\n\t}\n\t\n\tMatrix&lt;float&gt; matrix = Matrix&lt;float&gt;::join(\n\t\tparam::width(), param::height(),\n\t\tparam::divide_x(), param::divide_y(),\n\t\tmatrices,\n\t\tx_overlay,\n\t\ty_overlay);\n\t\t\n\tfor (unsigned int i = 0; i &lt; param::width(); i++) {\n\t\tfor (unsigned int j = 0; j &lt; param::height(); j++) {\n\t\t\tprintf(\"%.2f \", matrix.get(i, j));\n\t\t}\n\t\tprintf(\"\\n\");\n\t}\n\t\n\tdelete [] matrices;\n\tctx.quit();\n</code></transition><area id=\"106\" init-expr=\"[0]\" name=\"\" sx=\"165.0\" sy=\"76.0\" x=\"-599.5\" y=\"-238.0\" /><area id=\"112\" init-expr=\"ca::range(0, ctx.process_count())\" name=\"\" sx=\"204.0\" sy=\"81.0\" x=\"-600.5\" y=\"-115.0\" /></net></project>");
	std::vector<ca::Parameter*> parameters;
	parameters.push_back(&param::width);
	parameters.push_back(&param::divide_x);
	parameters.push_back(&param::divide_y);
	parameters.push_back(&param::height);

	ca::init(argc, argv, parameters);

	ca::NetDef *def_101 = new ca::NetDef(0, 101, spawn_101, false);
	def_101->register_transition(&transition_104);
	def_101->register_transition(&transition_115);
	def_101->register_transition(&transition_125);
	def_101->register_transition(&transition_130);
	ca::NetDef *defs[] = {def_101};
	ca::setup(1, defs);
	ca::spawn_net(0);
	ca::main();
	return 0;
}
