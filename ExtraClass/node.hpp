#ifndef NOBE_HPP
# define NOBE_HPP
# include "../containers.h"

template < class T >
class	ft::nobe
{
	public:
		typedef T				value_type;
		typedef typename T::key_type		key_type;
		typedef typename T::content_type	content_type;

	protected:
		value_type	_val;
		nobe*		_left;
		nobe*		_right;
		nobe*		_papa;
		char		_color;

	public:
		nobe(void) : _val(), _left(NULL), _right(NULL), _papa(NULL),
				_color('s') {};
		nobe(const value_type& val) : _val(val)
		{
			nobe*	left = new nobe;
			nobe*	right = new nobe;

			_left = left;
			_right = right;
			left->setPapa(this);
			right->setPapa(this);
			_papa = NULL;
			_color = 'r';
		};
		template < class U > nobe(const nobe<U>& mit) : _val(mit.getVal())
		{
			_left = mit.getLeft();
			_right = mit.getRight();
			_papa = mit.getPapa();
			_color = mit.getColor();
		};
		~nobe(void)
		{
			if (_papa)
			{
				_papa->setRight(NULL);
				_papa->setLeft(NULL);
			}
			if (_right && _right->is_nil())
			{
				_right->setPapa(NULL);
				delete _right;
			}
			if (_left && _left->is_nil())
			{
				_left->setPapa(NULL);
				delete _left;
			}
		}
};
#endif
