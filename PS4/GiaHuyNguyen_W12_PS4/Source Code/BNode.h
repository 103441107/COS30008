#pragma once

#include <stdexcept>

template<typename S>
struct BNode
{
    S key;
    BNode<S>* left;
    BNode<S>* right;
    
    static BNode<S> NIL;

    const S& findMax() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return right->empty() ? key : right->findMax();
    }

    const S& findMin() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return left->empty() ? key : left->findMin();
    }

    bool remove( const S& aKey, BNode<S>* aParent )
    {
        BNode<S>* x = this;
        BNode<S>* y = aParent;

        while ( !x->empty() )
        {
            if ( aKey == x->key )
            {
                break;
            }

            y = x;                                      // new parent
            
            x = aKey < x->key ? x->left : x->right;
        }

        if ( x->empty() )
        {
            return false;                               // delete failed
        }
        
        if ( !x->left->empty() )
        {
            const S& lKey = x->left->findMax();         // find max to left
            x->key = lKey;
            x->left->remove( lKey, x );
        }
        else
        {
            if ( !x->right->empty() )
            {
                const S& lKey = x->right->findMin();    // find min to right
                x->key = lKey;
                x->right->remove( lKey, x );
            }
            else
            {
                if ( y->left == x )
                {
                    y->left = &NIL;
                }
                else
                {
                    y->right = &NIL;
                }
                
                delete x;                               // free deleted node
            }
        }

        return true;
    }
    
    bool empty() const
    {
        return this == &NIL;
    }

    bool leaf() const
    {
        return left == &NIL && right == &NIL;
    }

    size_t height() const
    {
        if ( leaf() )
        {
            return 0;
        }
        return 1 + std::max( left->height(), right->height() );
    }

    bool insert( const S& aKey )
    {
        if ( aKey == key || empty() )
        {
            return false;
        }
        
        if ( aKey < key )
        {
            if ( left->empty() )
            {
                left = new BNode<S>( aKey );
            }
            else
            {
                return left->insert( aKey );
            }
        }
        else
        {
            if ( right->empty() )
            {
                right = new BNode<S>( aKey );
            }
            else
            {
                return right->insert( aKey );
            }
        }
        return true;
    }

    BNode()
    {
        left = &NIL;
        right = &NIL;
    }

    BNode( const S& aKey )
    {
        key = aKey;
        left = &NIL;
        right = &NIL;
    }

    BNode( S&& aKey )
    {
        key = std::move( aKey );
        left = &NIL;
        right = &NIL;
    }

    ~BNode()
    {
        remove(NULL, this);
    }
};

template<typename S>
BNode<S> BNode<S>::NIL;