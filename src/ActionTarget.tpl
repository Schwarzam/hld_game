//
// Created by gustavo on 08/10/2021.
//

template<typename T>
ActionTarget<T>::ActionTarget(const ActionMap<T> &map) : _actionMap(map) {

}

bool ActionTarget::processEvent(const sf::Event &event) const {
    bool res = false;
    for (auto& action : _eventsPoll){
        if (action.first == event){
            action.second(event);
            res = true;
            break;
        }
    }
    return res;
}

void ActionTarget::processEvents() const {
    for (auto& action : _eventsRealTime){
        if(action.first.test()){
            action.second(action.first._event);
        }
    }

}



template <typename T>
void ActionTarget<T>::bind(const T &key, const ActionTarget<T>::FuncType &callback) {
    const Action& action = _actionMap.get(key);
    if (action._type & Action::Type::RealTime)
        _eventsRealTime.emplace_back(action, callback);
    else
        _eventsPoll.emplace_back(action, callback);
}

void ActionTarget::unbind(const Action &action) {
    auto remove_func = [&action](const std::pair<Action, FuncType>& pair) -> bool{
        return pair.first == action;
    };

    if (action._type & Action::Type::RealTime)
        _eventsRealTime.remove_if(remove_func);
    else
        _eventsPoll.remove_if(remove_func);
}
