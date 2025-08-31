#include "rdb.h"

//definition of integerAttributes Operators  
bool integerAttribute::operator==(const Attr&right){
    const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val==right_casted->val;
}

bool integerAttribute::operator>(const Attr& right){
        const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
        if(right_casted==nullptr){
            return false;
        }
        else return this->val>right_casted->val;
    }

bool integerAttribute::operator<(const Attr& right){
        const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
        if(right_casted==nullptr){
            return false;
        }
        else return this->val<right_casted->val;
    }

bool integerAttribute::operator!=(const Attr& right){
        const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
        if(right_casted==nullptr){
            return false;
        }
        else return this->val!=right_casted->val;
    }

bool integerAttribute::operator>=(const Attr& right){
        const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
        if(right_casted==nullptr){
            return false;
        }
        else return ((this->val>right_casted->val)||(this->val==right_casted->val));
    }

bool integerAttribute::operator<=(const Attr& right){
        const integerAttribute *right_casted = dynamic_cast<const integerAttribute *>(&right);
        if(right_casted==nullptr){
            return false;
        }
        else return ((this->val<right_casted->val)||(this->val==right_casted->val));
    }


//definition of floatAttributes Operators 
bool floatAttribute::operator==(const Attr&right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val==right_casted->val;
}
bool floatAttribute::operator>(const Attr& right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val>right_casted->val;
}
bool floatAttribute::operator<(const Attr& right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val<right_casted->val;
}
bool floatAttribute::operator!=(const Attr& right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val!=right_casted->val;
}
bool floatAttribute::operator>=(const Attr& right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return ((this->val>right_casted->val)||(this->val==right_casted->val));
}
bool floatAttribute::operator<=(const Attr& right){
    const floatAttribute *right_casted = dynamic_cast<const floatAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return ((this->val<right_casted->val)||(this->val==right_casted->val));
}


//definition of stringAttributes Operators 
bool stringAttribute::operator==(const Attr&right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val==right_casted->val;
}
bool stringAttribute::operator>(const Attr& right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val>right_casted->val;
}
bool stringAttribute::operator<(const Attr& right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val<right_casted->val;
}
bool stringAttribute::operator!=(const Attr& right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return this->val!=right_casted->val;
}
bool stringAttribute::operator>=(const Attr& right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return ((this->val>right_casted->val)||(this->val==right_casted->val));
}
bool stringAttribute::operator<=(const Attr& right){
    const stringAttribute *right_casted = dynamic_cast<const stringAttribute *>(&right);
    if(right_casted==nullptr){
        return false;
    }
    else return ((this->val<right_casted->val)||(this->val==right_casted->val));
}
