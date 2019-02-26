let component = ReasonReact.statelessComponent("App");

type item = {
  id: int,
  title: string,
};

let initialItems = [
  {id: 1, title: "First item"},
  {id: 2, title: "Second item"},
];

let make = _children => {
  ...component,
  render: _self =>
    <div className="todoapp">
      <header className="header">
        <h1> {ReasonReact.string("todos")} </h1>
      </header>
      <section className="main">
        <ul className="todo-list">
          {ReasonReact.array(
             Array.of_list(
               List.map(
                 item =>
                   <ToDoItem
                     key={string_of_int(item.id)}
                     title={item.title}
                   />,
                 initialItems,
               ),
             ),
           )}
        </ul>
      </section>
    </div>,
};
