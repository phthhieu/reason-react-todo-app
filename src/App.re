let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div className="todoapp">
      <header className="header">
        <h1> {ReasonReact.string("todos")} </h1>
      </header>
    </div>,
};
