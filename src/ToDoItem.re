let component = ReasonReact.statelessComponent("ToDoItem");

let make = (~title, ~complete, ~onClick, _children) => {
  ...component,
  render: _self => {
    let className = complete ? "line-through" : "";
    <li onClick className>
      <div className="view">
        <label> {ReasonReact.string(title)} </label>
      </div>
    </li>;
  },
};
