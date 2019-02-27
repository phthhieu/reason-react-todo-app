type item = {
  id: int,
  title: string,
  complete: bool,
};

type state = {
  items: list(item),
  currentText: string,
};

type action =
  | EnterKeyDown
  | UpdateInputText(string)
  | ToggleStatus(int);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    items: [{id: 1, title: "First item", complete: true}],
    currentText: "",
  },
  reducer: (action, state) => {
    let {items, currentText} = state;
    switch (action) {
    | EnterKeyDown =>
      ReasonReact.Update({
        ...state,
        items: [
          {id: List.length(items) + 1, title: currentText, complete: false},
          ...items,
        ],
      })
    | UpdateInputText(text) =>
      ReasonReact.Update({...state, currentText: text})
    | ToggleStatus(id) =>
      ReasonReact.Update({
        ...state,
        items:
          List.map(
            item =>
              item.id == id ? {...item, complete: !item.complete} : item,
            state.items,
          ),
      })
    };
  },
  render: self =>
    <div className="todoapp">
      <header className="header">
        <h1> {ReasonReact.string("todos")} </h1>
        <input
          className="new-todo"
          placeholder="Enter new item"
          onKeyDown={event =>
            if (ReactEvent.Keyboard.keyCode(event) === 13) {
              ReactEvent.Keyboard.preventDefault(event);
              self.send(EnterKeyDown);
            }
          }
          onChange={event =>
            self.send(UpdateInputText(ReactEvent.Form.target(event)##value))
          }
        />
      </header>
      <section className="main">
        <ul className="todo-list">
          {ReasonReact.array(
             Array.of_list(
               List.map(
                 item =>
                   <ToDoItem
                     onClick={_e => self.send(ToggleStatus(item.id))}
                     key={string_of_int(item.id)}
                     title={item.title}
                     complete={item.complete}
                   />,
                 self.state.items,
               ),
             ),
           )}
        </ul>
      </section>
    </div>,
};
