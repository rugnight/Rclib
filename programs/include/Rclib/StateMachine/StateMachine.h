/**
 * @file StateMachine.h
 * @brief 
 * @author rugnight
 * @version 
 * @date 2014-04-09
 */

#ifndef __RCLIB_STATE_MACHINE_H__
#define __RCLIB_STATE_MACHINE_H__

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace rc {

class State;
class StateMachine;

typedef std::shared_ptr<State> StatePtr;
typedef std::function<bool(const StatePtr& from, const StatePtr& to)> TransitEvalFunc;

struct Transition {
    Transition(const std::string _from, const std::string _to)
    {
        from = _from;
        to = _to;
        eval_func = nullptr;
    }
    Transition(const std::string _from, const std::string _to,
            TransitEvalFunc _eval_func)
    {
        from = _from;
        to = _to;
        eval_func = _eval_func;
    }

    std::string from;
    std::string to;
    TransitEvalFunc eval_func;
};

class State {
    public:
        State() = delete;
        State(const std::string &name);
        virtual ~State();

        virtual void OnAdd();
        virtual void OnEnter();
        virtual void OnUpdate();
        virtual void OnExit();
        virtual void OnRemove();

        const std::string &name() { return name_; };

    private:
        std::string name_;
};

class StateMachine {
    public:
        StateMachine();
        virtual ~StateMachine();

        //! @brief 更新
        void Update();

        //! @brief 開始状態を設定
        void SetRoot(const std::string root_name);

        //! @brief 遷移を実行
        bool Transit(const std::string &transit_name);

        //! 状態の追加
        bool AddState(StatePtr state);

        //! @brief 遷移条件関数付きの遷移を追加
        bool AddTransition(const std::string &from, const std::string &to,
                const std::string &transit_name,
                TransitEvalFunc eval_func);

        //! @brief 遷移を追加
        bool AddTransition(const std::string &from, const std::string &to,
                const std::string &transit_name);

        //! @brief 現在の状態の取得
        const StatePtr &crrent() { return current_; };

    private:
        //! @brief 状態を設定
        bool SetState(const std::string &state_name);

        std::string root_name_;
        StatePtr current_;

        std::map<std::string, StatePtr> states_;
        std::map<std::string, Transition> transitions_;
};

}

#endif // __FILENAME__H__
