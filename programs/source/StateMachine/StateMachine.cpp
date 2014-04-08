/**
 * @file StateMachine.cpp
 * @brief 
 * @author rugnight
 * @version 
 * @date 2014-04-09
 */

#include "Rclib/StateMachine/StateMachine.h"

namespace rc {

// ==================================================
// class State
State::State(const std::string &name) : name_(name)
{
}
State::~State()
{
}

void State::OnAdd()
{
    printf("[%s] OnAdd()\n", name_.c_str());
}
void State::OnEnter()
{
    printf("[%s] OnEnter()\n", name_.c_str());
}
void State::OnUpdate()
{
    printf("[%s] OnUpdate()\n", name_.c_str());
}
void State::OnExit()
{
    printf("[%s] OnExit()\n", name_.c_str());
}
void State::OnRemove()
{
    printf("[%s] OnRemove()\n", name_.c_str());
}

// ==================================================
// class StateMachine
StateMachine::StateMachine() : current_(nullptr)
{
    root_name_ = "";
}
StateMachine::~StateMachine()
{
}

//! @brief 更新
void StateMachine::Update()
{
    if (nullptr == current_) {
        if (false == SetState(root_name_)) {
            // no set root
            return;
        }
    }
    current_->OnUpdate();
}

//! @brief 開始状態を設定
void StateMachine::SetRoot(const std::string root_name)
{
    root_name_ = root_name;
}

//! @brief 遷移を実行
bool StateMachine::Transit(const std::string &transit_name)
{
    auto it = transitions_.find(transit_name);
    if (transitions_.end() == it) {
        // 遷移が存在しない
        printf("no transit [%s]\n", transit_name.c_str());
        return false;
    }
    Transition transit = it->second;
    if (current_->name() != transit.from) {
        // 今の状態ではその遷移はできない
        printf("no match [%s -> %s in %s]\n", transit.from.c_str(),
                transit.to.c_str(), transit_name.c_str());
        return false;
    }
    if (transit.eval_func) {
        auto state_to = states_.find(transit.to);
        if (states_.end() == state_to) {
            // 遷移先の状態が存在しない
            return false;
        }
        if (false == transit.eval_func(current_, state_to->second)) {
            // 遷移条件を満たしていない
            return false;
        }
    }

    return SetState(transit.to);
}

//! 状態の追加
bool StateMachine::AddState(StatePtr state)
{
    auto it = states_.find(state->name());
    if (states_.end() != it) {
        return false;
    }

    states_.insert(std::make_pair(state->name(), state));
    return true;
}

//! @brief 遷移条件関数付きの遷移を追加
bool StateMachine::AddTransition(const std::string &from, const std::string &to,
        const std::string &transit_name,
        TransitEvalFunc eval_func)
{
    auto it = transitions_.find(transit_name);
    if (transitions_.end() != it) {
        return false;
    }

    transitions_.insert(
            std::make_pair(transit_name, Transition(from, to, eval_func)));
    return true;
}

//! @brief 遷移を追加
bool StateMachine::AddTransition(const std::string &from, const std::string &to,
        const std::string &transit_name)
{
    return AddTransition(from, to, transit_name, nullptr);
}

//! @brief 状態を設定
bool StateMachine::SetState(const std::string &state_name)
{
    auto it = states_.find(state_name);
    if (states_.end() == it) {
        printf("no state [%s]\n", state_name.c_str());
        return false;
    }
    if (current_) {
        current_->OnExit();
    }
    current_ = it->second;
    current_->OnEnter();
    return true;
}

}

